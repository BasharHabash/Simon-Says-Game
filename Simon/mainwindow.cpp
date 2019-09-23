#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamelogic.h"

#include <QList>
#include <QTime>
#include <QTimer>
#include <QThread>
#include <QMessageBox>
/*
 * Bashar Habash
 * Boden Archuleta
 *
 * Assignment 5: A QT Simon Game
 *
 * An implementation of the mainwindow functions
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initial conditions
    blinkSpeed = 150;
    clickSpeed = 100;
    sequenceSpeed = 2000;
    highestScore = 0;
    sequencePos = 0;

    ui->startButton->setEnabled(true);
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->roundLCD->display(highestScore);
    ui->highScoreLCD->display(highestScore);
    ui->turn->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simonLogic;
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);

    // Computers turn
    simonLogic = new gameLogic();
    showSequence(simonLogic->sequence, sequenceSpeed);
}

void MainWindow::on_blueButton_clicked()
{
    ui->blueButton->setStyleSheet("background-color:gray");
    QTimer::singleShot(clickSpeed, this, SLOT(blinkBlue()));

    if (simonLogic->sequence[sequencePos] == 0)
    {
        sequencePos ++;
        updateProgressBar();
        if(simonLogic->sequence.size() == sequencePos)
        {
            simonLogic->nextTurn();
                        pause(500);
            showSequence(simonLogic->sequence, sequenceSpeed);
        }

    } else {
        lostGame();
    }
}

void MainWindow::on_redButton_clicked()
{
    ui->redButton->setStyleSheet("background-color:gray");
    QTimer::singleShot(clickSpeed, this, SLOT(blinkRed()));

    if (simonLogic->sequence[sequencePos] == 1)
    {
        sequencePos ++;
        updateProgressBar();
        if(simonLogic->sequence.size() == sequencePos)
        {
            simonLogic->nextTurn();
            pause(500);
            showSequence(simonLogic->sequence, sequenceSpeed);
        }
    } else {
        lostGame();
    }
}

void MainWindow::showSequence(QList<int> sequence, int speed)
{
    //lock ui
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->roundLCD->display(sequencePos + 1);
    ui->turn->setText("Computer");

    // Check highscore
    if (highestScore < sequencePos + 1)
    {
        highestScore = sequencePos + 1;
        ui->highScoreLCD->display(sequencePos + 1);
    }

    // Display computer sequence
    for (int i = 0; i < sequence.size(); i++)
    { 
        pause(speed);
        if (sequence[i] == 0)
        {
            ui->blueButton->setStyleSheet("background-color:gray");
            QTimer::singleShot(blinkSpeed, this, SLOT(blinkBlue()));
        }
        else if(sequence[i] == 1)
        {
            ui->redButton->setStyleSheet("background-color:gray");
            QTimer::singleShot(blinkSpeed, this, SLOT(blinkRed()));
        }
    }
    // reset sequence tracker
    sequencePos = 0;

    pause(500);

    //unlock ui and increase game speed
    if (sequenceSpeed > 400)
    {
        sequenceSpeed -= 200;
    }
    ui->blueButton->setEnabled(true);
    ui->redButton->setEnabled(true);
    ui->turn->setText("User");
}

void MainWindow::blinkBlue()
{
    ui->blueButton->setStyleSheet("background-color:rgb(32, 74, 135)");
}

void MainWindow::blinkRed()
{
    ui->redButton->setStyleSheet("background-color:rgb(164, 0, 0)");
}

void MainWindow::lostGame()
{
    //reset ui
    ui->blueButton->setEnabled(false);
    ui->redButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->progressBar->setValue(0);
    ui->roundLCD->display(0);
    ui->turn->setText("");

    //game over message
    QMessageBox endOfGame;
    endOfGame.setText("Game Over! Sequence entered is incorrect.");
    endOfGame.exec();

    //reset game data
    blinkSpeed = 500;
    clickSpeed = 150;
    sequenceSpeed = 2000;
    sequencePos = 0;
    simonLogic->sequence.clear();
}

void MainWindow::pause(int time)
{
    QTime endTime = QTime::currentTime().addMSecs(time);
    while(QTime::currentTime()< endTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::updateProgressBar()
{
    double temp = static_cast<double>(sequencePos) / static_cast<double>(simonLogic->sequence.length());
    temp *= 100;
    int val = static_cast<int>(temp);
    ui->progressBar->setValue(val);
}
