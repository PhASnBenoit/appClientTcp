#ifndef CIHMAPPCLIENTTCP_H
#define CIHMAPPCLIENTTCP_H

#include <QMainWindow>
#include <QTcpSocket>
#include "cclienttcp.h"

namespace Ui {
class CIhmAppClientTcp;
}

class CIhmAppClientTcp : public QMainWindow
{
    Q_OBJECT

public:
    explicit CIhmAppClientTcp(QWidget *parent = 0);
    ~CIhmAppClientTcp();

private slots:
    void on_pbConnecter_clicked();
    void on_pbEnvoyer_clicked();
    void onEvenementClient(QString eve);
    void onDataClient(QString data);
    void onErrorClient(QAbstractSocket::SocketError err);

private:
    Ui::CIhmAppClientTcp *ui;
    CClientTcp *client;
};

#endif // CIHMAPPCLIENTTCP_H
