/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(531, 413);
        horizontalLayoutWidget = new QWidget(About);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 531, 411));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::RichText);
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "\303\200 propos ...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("About", "<html><head/><body><p><img src=\":/fojek.jpg\"/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">crcQuest v2.0</span><br/></p><p>Cr\303\251\303\251 par Marc Fortier \303\240 la demande de fr\303\250re Fran\303\247ois-Xavier (mais livr\303\251 6 ans en retard). <br/></p><p>Pour t\303\251l\303\251charger la derni\303\250re version, ouvrez un terminal et entrez :</p><p>git clone <a href=\"https://www.github.com/fojek/JeuQuestionnaire\"><span style=\" text-decoration: underline; color:#0000ff;\">https://www.github.com/fojek/JeuQuestionnaire</span></a></p><p><br/></p><p><span style=\" text-decoration: underline;\">Changements \303\240 la version 2:</span></p><p>- Ajout d'un quatri\303\250me bouton;</p><p>- Chang\303\251 les num\303\251ros par une couleur d'\303\251quipe;</p><p>- Ajout\303\251 la correspondance de la couleur de background;</p><p>- Corrig\303\251 bogue qui obligeait \303\240 r\303\251initialiser au d\303\251but.</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
