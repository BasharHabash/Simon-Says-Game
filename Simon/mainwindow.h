#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "gamelogic.h"
#include <QMainWindow>
#include <QList>

/*
 * Bashar Habash
 * Boden Archuleta
 *
 * Assignment 5: A QT Simon Game
 *
 * The header file of the functions of the mainwindow
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Track the position in the sequence list.
    int sequencePos;

    // How fast the buttons blink during the computers turn
    int blinkSpeed;

    // How fast the buttons blink when the player clicks on them
    int clickSpeed;

    // The speed of the computers moves, increases every turn
    int sequenceSpeed;

    // Track the highest score
    int highestScore;

private slots:
    /*
     * When start button is clicked it initiates the game.
     * Calling the display of the first computer turn.
     */
    void on_startButton_clicked();

    /*
     * Registers the players input and makes sure it matches the
     * computers sequence, if not the game is lost.
     */
    void on_blueButton_clicked();
    void on_redButton_clicked();

    /*
     * Displayes the computers turns sequence
     */
    void showSequence(QList<int>, int);

    /*
     * A helper methods to make a delay and a blinking in the buttons
     */
    void blinkBlue();
    void blinkRed();

    /*
     * Displays a popup message that the game is lost and resets the conditions
     */
    void lostGame();

    /*
     * Delays all activities in the project for a agiven number of msec
     */
    void pause(int);


private:
    Ui::MainWindow *ui;
    gameLogic* simonLogic;

    //calculates the percentage of moves the player has completed on their turn,
    //then updates the progress bar accordingly.
    void updateProgressBar();
};

#endif // MAINWINDOW_H
