#ifndef JEUQUESTIONNAIRE_H
#define JEUQUESTIONNAIRE_H

#include <QMainWindow>

namespace Ui {
class JeuQuestionnaire;
}

class JeuQuestionnaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit JeuQuestionnaire(QWidget *parent = 0);
    ~JeuQuestionnaire();

private:
    Ui::JeuQuestionnaire *ui;
};

#endif // JEUQUESTIONNAIRE_H
