#include "crcQuest.h"
#include "ui_crc_quest.h"
#include "ui_about.h"
#include <QTimer>
#include "global.h"
#include <wiringPi.h>
#include <iostream>
#include <string>
using namespace std;

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
    // Action du timer
    --timerCount;
    if (timerCount <= 0)
    {
        /// Variables
        // On regroupe les labels en tableau, plus pratique ...
        QLabel *labels[4]={ui->Equipe1,ui->Equipe2,ui->Equipe3,ui->Equipe4};
        // Le texte a afficher selon le bouton
        const string TEXTE_POSITION[NB_BOUTONS+1] = {"...", "Bleu", "Rouge", "Vert", "Jaune"};
        const string COULEUR_SS[NB_BOUTONS+1] = {"gray;", "blue;", "red;", "green;", "yellow;"};
        const QString BASE_STYLESHEET = "font: italic 18pt 'Verdana'; \
                                         border : 2px solid; \
                                         border-radius : 8px; \
                                         border-color : black; \
                                         background-color : ";

        refreshHMI->stop();
        refreshHMI->start();

        // Pour chaque resultat ...
        for(int i=0; i<NB_BOUTONS; ++i)
        {
            // Et pour tous les boutons ...
            for(int j=0; j<NB_BOUTONS+1; ++j)
            {
                // Est-ce que le resultat i est le bouton j ?
                if(resultat[i] == j)
                {
                    // Si oui on affiche le nom correspondant a la position
                    // Et on change la couleur du background pour correspondre a la couleur de l'equipe
                    labels[i]->setText(QString::number(i+1) + " : " + QString::fromStdString(TEXTE_POSITION[j]));
                    labels[i]->setStyleSheet(BASE_STYLESHEET + QString::fromStdString(COULEUR_SS[j]));
                }
            }
        }
    }
}

void CRC_Quest::on_pushButton_clicked()
{
    exitGlobal = 0;
    delayMicroseconds(1000);
    exitGlobal = 1;
}

void CRC_Quest::on_actionA_propos_triggered()
{
    about = new QDialog(0,0);

    Ui_About aboutUi;
    aboutUi.setupUi(about);

    about->show();
}

void CRC_Quest::on_actionQuitter_triggered()
{
    exitGlobal=0;
    delete ui;
}
