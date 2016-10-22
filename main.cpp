#include "crcQuest.h"
#include <QApplication>
#include <wiringPi.h>
#include "jeuQuestionnaire_GPIO.cpp"

int main(int argc, char *argv[])
{

    wiringPiSetup();

    // Les boutons en tant qu'entrées
    for(int i=0; i<4; ++i)
    {
        pinMode (BOUTON[i], INPUT);
    }

    // Le buzzer en tant que sortie
    pinMode (BUZZER, OUTPUT);

    piThreadCreate (WDT);
    //piThreadCreate (Request);

    QApplication a(argc, argv);
    CRC_Quest w;
    w.show();

    return a.exec();
}
