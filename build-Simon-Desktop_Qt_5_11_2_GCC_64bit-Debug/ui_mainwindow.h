/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *startButton;
    QPushButton *blueButton;
    QPushButton *redButton;
    QProgressBar *progressBar;
    QLabel *progress;
    QLabel *round;
    QLCDNumber *roundLCD;
    QLCDNumber *highScoreLCD;
    QLabel *highScore;
    QLabel *turn;
    QLabel *highScore_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(559, 410);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(220, 280, 121, 41));
        blueButton = new QPushButton(centralWidget);
        blueButton->setObjectName(QStringLiteral("blueButton"));
        blueButton->setGeometry(QRect(110, 100, 161, 151));
        blueButton->setStyleSheet(QStringLiteral("background-color: rgb(32, 74, 135);"));
        redButton = new QPushButton(centralWidget);
        redButton->setObjectName(QStringLiteral("redButton"));
        redButton->setGeometry(QRect(290, 100, 161, 151));
        redButton->setStyleSheet(QStringLiteral("background-color: rgb(164, 0, 0);"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(380, 60, 118, 23));
        progressBar->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(238, 238, 236);"));
        progressBar->setValue(24);
        progress = new QLabel(centralWidget);
        progress->setObjectName(QStringLiteral("progress"));
        progress->setGeometry(QRect(400, 30, 67, 17));
        round = new QLabel(centralWidget);
        round->setObjectName(QStringLiteral("round"));
        round->setGeometry(QRect(90, 30, 51, 17));
        roundLCD = new QLCDNumber(centralWidget);
        roundLCD->setObjectName(QStringLiteral("roundLCD"));
        roundLCD->setGeometry(QRect(80, 60, 64, 23));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        roundLCD->setFont(font);
        roundLCD->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        highScoreLCD = new QLCDNumber(centralWidget);
        highScoreLCD->setObjectName(QStringLiteral("highScoreLCD"));
        highScoreLCD->setGeometry(QRect(20, 310, 64, 23));
        highScoreLCD->setFont(font);
        highScoreLCD->setStyleSheet(QLatin1String("\n"
"background-color: rgb(0, 0, 0);"));
        highScore = new QLabel(centralWidget);
        highScore->setObjectName(QStringLiteral("highScore"));
        highScore->setGeometry(QRect(20, 280, 81, 17));
        turn = new QLabel(centralWidget);
        turn->setObjectName(QStringLiteral("turn"));
        turn->setGeometry(QRect(450, 310, 81, 21));
        turn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        highScore_3 = new QLabel(centralWidget);
        highScore_3->setObjectName(QStringLiteral("highScore_3"));
        highScore_3->setGeometry(QRect(450, 280, 81, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 559, 22));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Start Game", nullptr));
        blueButton->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        redButton->setText(QApplication::translate("MainWindow", "Red", nullptr));
        progress->setText(QApplication::translate("MainWindow", "Progress", nullptr));
        round->setText(QApplication::translate("MainWindow", "Round ", nullptr));
        highScore->setText(QApplication::translate("MainWindow", "High Score ", nullptr));
        turn->setText(QString());
        highScore_3->setText(QApplication::translate("MainWindow", "Whos turn:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
