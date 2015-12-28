#include "crc_quest.h"
#include <QApplication>
#include <wiringPi.h>
#include "jeuQuestionnaire_GPIO.cpp"

int main(int argc, char *argv[])
{

    wiringPiSetup();

    /* Les boutons en tant qu'entrées */
    pinMode (BOUTON_1, INPUT);
    pinMode (BOUTON_2, INPUT);
    pinMode (BOUTON_3, INPUT);
    pinMode (BOUTON_4, INPUT);

    piThreadCreate (WDT);
    //piThreadCreate (Request);

    QApplication a(argc, argv);
    CRC_Quest w;
    w.show();

    return a.exec();
}
