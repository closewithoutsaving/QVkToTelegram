#ifndef REQUEST_H
#define REQUEST_H

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QString>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "variables.h"

class Request
{
public:
    Request();

    void messagesGetDialogs();

    void sendMessage();
};

#endif // REQUEST_H
