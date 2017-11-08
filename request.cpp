#include "request.h"

Request::Request()
{

}

void Request::messagesGetDialogs()
{
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl u = QUrl("https://api.vk.com/method/messages.getDialogs?count=10&unread=1&access_token="
                  + Variables::token
                  + "&v=5.57");

    QNetworkRequest req( u );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();

    QString answer = "";
    if (reply->error() == QNetworkReply::NoError) {

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject obj1 = doc.object();
        QJsonObject obj2 = obj1["response"].toObject();

        if(obj2["count"].toInt() == 0)
        {
            return;
        }

        int count = obj2["count"].toInt();

        for (int i = 0; i < count; i++)
        {
            QJsonArray obj3 = obj2["items"].toArray();
            QJsonObject obj4 = obj3[0].toObject();
            QJsonObject obj5 = obj4["message"].toObject();

            //Is it conf?
            bool isConf = obj5.contains("admin_id");

            QString str = obj5["body"].toString();

            if(isConf)
            {
//              Variables::peer_id_second_thread = 2000000000 + obj5["chat_id"].toInt();
                return;
            }
            else
            {
                Variables::peer_id_second_thread = obj5["user_id"].toDouble();
            }

            Request::sendMessage();
        }
    }
    else
    {
        answer = "Failure sended\n" + QString(reply->errorString());
    }

    delete reply;
}

void Request::sendMessage()
{
    Variables::answer = Variables::answer.replace(" ", "+");

    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QUrl u = QUrl("https://api.vk.com/method/messages.send?&random_id=" + QString::number(Variables::getRandom())
                  + "&peer_id=" + QString::number(Variables::peer_id_second_thread)
                  + "&message=" + Variables::answer +
                  + "&access_token=" + Variables::token
                  + "&v=5.57");

    QNetworkRequest req( u );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();

    QString answer;
    if (reply->error() == QNetworkReply::NoError) {
        answer = "Success sended\n" + QString(reply->readAll());
        qDebug() << answer;
    }
    else {
        answer = "Failure sended\n" + QString(reply->errorString());
        qDebug() << answer;
    }

    delete reply;
}
