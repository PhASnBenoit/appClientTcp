#ifndef CCLIENTTCP_H
#define CCLIENTTCP_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

class CClientTcp : public QObject
{
    Q_OBJECT
public:
    explicit CClientTcp(QObject *parent = 0);
    ~CClientTcp();
    int emettre(QString mess);
    int connecter(QString adr, QString port);
    void deconnecter();

signals:
    void sigData(QString data);
    void sigErreur(QAbstractSocket::SocketError);
    void sigEvenement(QString eve);

public slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onSocketError(QAbstractSocket::SocketError);

private:
    QTcpSocket *sock;

};

#endif // CCLIENTTCP_H
