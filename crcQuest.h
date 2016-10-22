#ifndef CRC_QUEST_H
#define CRC_QUEST_H

#include <QMainWindow>

namespace Ui {
class CRC_Quest;
class About;
}

class CRC_Quest : public QMainWindow
{
    Q_OBJECT

public:
    explicit CRC_Quest(QWidget *parent = 0);
    ~CRC_Quest();

private slots:
    void timerTimeout();

    void on_pushButton_clicked();

    void on_actionA_propos_triggered();

    void on_actionQuitter_triggered();

private:
    Ui::CRC_Quest *ui;
    QTimer *refreshHMI;
    QDialog *about;
    int timerCount;
};

#endif // CRC_QUEST_H
