#include "crc_quest.h"
#include "ui_crc_quest.h"
#include <QTimer>
#include "global.h"
#include <wiringPi.h>

CRC_Quest::CRC_Quest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CRC_Quest)
{
    ui->setupUi(this);

    /* Timer pour le scan time de l'interface. 50ms? */
    refreshHMI = new QTimer(this);

    refreshHMI->setInterval(10);
    timerCount = 0;
    refreshHMI->start(1);

    /* Création du timer */
    connect(refreshHMI, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

CRC_Quest::~CRC_Quest()
{
    delete ui;
}

void CRC_Quest::timerTimeout()
{
    --timerCount;
    if (timerCount <= 0)
    {
        refreshHMI->stop();
        refreshHMI->start();

        /* Affiche les resultats */
        ui->Equipe1->setText("# : " + QString::number(resultat[0]));
        ui->Equipe2->setText("# : " + QString::number(resultat[1]));
        ui->Equipe3->setText("# : " + QString::number(resultat[2]));
        ui->Equipe4->setText("# : " + QString::number(resultat[3]));
    }
}

void CRC_Quest::on_pushButton_clicked()
{
    exit_global = 0;
    delayMicroseconds(1000);
    exit_global = 1;
}
