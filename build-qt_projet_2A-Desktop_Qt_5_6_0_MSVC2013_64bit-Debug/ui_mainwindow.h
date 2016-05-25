/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSoloMode;
    QPushButton *btnAssiste;
    QPushButton *btnManuel;
    QWidget *formLayoutWidget;
    QFormLayout *flBallDetected;
    QLabel *label;
    QLabel *lblNbB;
    QLabel *label_4;
    QLabel *lblNbBb;
    QLabel *label_3;
    QLabel *lblNbBv;
    QLabel *label_2;
    QLabel *lblNbBr;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnRight;
    QPushButton *bbtnDown;
    QPushButton *btnLeft;
    QPushButton *btnUp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(612, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 291, 381));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(310, 10, 291, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnSoloMode = new QPushButton(horizontalLayoutWidget);
        btnSoloMode->setObjectName(QStringLiteral("btnSoloMode"));

        horizontalLayout->addWidget(btnSoloMode);

        btnAssiste = new QPushButton(horizontalLayoutWidget);
        btnAssiste->setObjectName(QStringLiteral("btnAssiste"));

        horizontalLayout->addWidget(btnAssiste);

        btnManuel = new QPushButton(horizontalLayoutWidget);
        btnManuel->setObjectName(QStringLiteral("btnManuel"));

        horizontalLayout->addWidget(btnManuel);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(310, 160, 291, 231));
        flBallDetected = new QFormLayout(formLayoutWidget);
        flBallDetected->setSpacing(6);
        flBallDetected->setContentsMargins(11, 11, 11, 11);
        flBallDetected->setObjectName(QStringLiteral("flBallDetected"));
        flBallDetected->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        flBallDetected->setWidget(0, QFormLayout::LabelRole, label);

        lblNbB = new QLabel(formLayoutWidget);
        lblNbB->setObjectName(QStringLiteral("lblNbB"));

        flBallDetected->setWidget(0, QFormLayout::FieldRole, lblNbB);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        flBallDetected->setWidget(1, QFormLayout::LabelRole, label_4);

        lblNbBb = new QLabel(formLayoutWidget);
        lblNbBb->setObjectName(QStringLiteral("lblNbBb"));

        flBallDetected->setWidget(1, QFormLayout::FieldRole, lblNbBb);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        flBallDetected->setWidget(2, QFormLayout::LabelRole, label_3);

        lblNbBv = new QLabel(formLayoutWidget);
        lblNbBv->setObjectName(QStringLiteral("lblNbBv"));

        flBallDetected->setWidget(2, QFormLayout::FieldRole, lblNbBv);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        flBallDetected->setWidget(3, QFormLayout::LabelRole, label_2);

        lblNbBr = new QLabel(formLayoutWidget);
        lblNbBr->setObjectName(QStringLiteral("lblNbBr"));

        flBallDetected->setWidget(3, QFormLayout::FieldRole, lblNbBr);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(310, 60, 291, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnRight = new QPushButton(gridLayoutWidget);
        btnRight->setObjectName(QStringLiteral("btnRight"));

        gridLayout->addWidget(btnRight, 1, 3, 1, 1);

        bbtnDown = new QPushButton(gridLayoutWidget);
        bbtnDown->setObjectName(QStringLiteral("bbtnDown"));

        gridLayout->addWidget(bbtnDown, 2, 2, 1, 1);

        btnLeft = new QPushButton(gridLayoutWidget);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));

        gridLayout->addWidget(btnLeft, 1, 1, 1, 1);

        btnUp = new QPushButton(gridLayoutWidget);
        btnUp->setObjectName(QStringLiteral("btnUp"));

        gridLayout->addWidget(btnUp, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnSoloMode->setText(QApplication::translate("MainWindow", "Solo", 0));
        btnAssiste->setText(QApplication::translate("MainWindow", "Assist\303\251", 0));
        btnManuel->setText(QApplication::translate("MainWindow", "Manuel", 0));
        label->setText(QApplication::translate("MainWindow", "Nombre de balles vues :", 0));
        lblNbB->setText(QApplication::translate("MainWindow", "0", 0));
        label_4->setText(QApplication::translate("MainWindow", "Nombre de balles blanches vues :", 0));
        lblNbBb->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", "Nombre de balles vertes vues :", 0));
        lblNbBv->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "Nombre de balles rouges vues :", 0));
        lblNbBr->setText(QApplication::translate("MainWindow", "0", 0));
        btnRight->setText(QApplication::translate("MainWindow", "Right", 0));
        bbtnDown->setText(QApplication::translate("MainWindow", "Down", 0));
        btnLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        btnUp->setText(QApplication::translate("MainWindow", "Up", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
