#include "cihmappclienttcp.h"
#include "ui_cihmappclienttcp.h"

CIhmAppClientTcp::CIhmAppClientTcp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CIhmAppClientTcp)
{
    ui->setupUi(this);
    ui->pbConnecter->setEnabled(true);
    ui->pbEnvoyer->setEnabled(false);

    client = new CClientTcp(this);
    connect(client, SIGNAL(sigEvenement(QString)), this, SLOT(onEvenementClient(QString)));
    connect(client, SIGNAL(sigErreur(QAbstractSocket::SocketError)), this, SLOT(onErrorClient(QAbstractSocket::SocketError)));
    connect(client, SIGNAL(sigData(QString)), this, SLOT(onDataClient(QString)));
}

CIhmAppClientTcp::~CIhmAppClientTcp()
{
    delete client;
    delete ui;
}

//////////////////////////////////////  SLOTs ///////////////////////////////////////////
/// IHM
void CIhmAppClientTcp::on_pbConnecter_clicked()
{
    if (ui->pbConnecter->text() == "Connexion") {
        client->connecter(ui->leAdrServeur->text(), ui->lePortServeur->text());
        ui->pbConnecter->setText("Déconnexion");
    } else {
        client->deconnecter();
        ui->pbConnecter->setText("Connexion");
    } // else
    }

void CIhmAppClientTcp::on_pbEnvoyer_clicked()
{
        client->emettre(ui->leEmission->text());
        ui->leEmission->clear();
        ui->leEmission->setFocus();
}


/// AUTRES OBJETS
void CIhmAppClientTcp::onEvenementClient(QString eve)
{
    if (eve == "CON") {
        ui->pbEnvoyer->setEnabled(true);
        ui->teReception->append("Connecté au serveur");
    } // CON
    if (eve=="DEC") {
        ui->pbEnvoyer->setEnabled(false);
        ui->teReception->append("Perte de connexion du serveur");
    } // DEC
}

void CIhmAppClientTcp::onDataClient(QString data)
{
    ui->teReception->append(data);
    qDebug() << "CIhmAppClientTcp::onDataClient " << data;
}

void CIhmAppClientTcp::onErrorClient(QAbstractSocket::SocketError err)
{
    switch (err) {
      case QAbstractSocket::ConnectionRefusedError:
        ui->teReception->append("Connexion refusée par le serveur !");
      break;
    case QAbstractSocket::NetworkError:
      ui->teReception->append("Coupure de liaison réseau !");
    break;
    default:
        ui->teReception->append("Erreur réseau à déterminer !");
      break;
    } // sw
}
