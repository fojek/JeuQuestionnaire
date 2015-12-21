#include "jeuquestionnaire.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JeuQuestionnaire w;
    w.show();

    return a.exec();
}
