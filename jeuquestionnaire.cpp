#include "jeuquestionnaire.h"
#include "ui_jeuquestionnaire.h"

JeuQuestionnaire::JeuQuestionnaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JeuQuestionnaire)
{
    ui->setupUi(this);
}

JeuQuestionnaire::~JeuQuestionnaire()
{
    delete ui;
}
