#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QList>

/*
 * Bashar Habash
 * Boden Archuleta
 *
 * Assignment 5: AQT Simon Game
 *
 * The interface of the computers logic
 */
class gameLogic
{
public:
    /*
     * Makes a new logic and calls adding a number to the sequence.
     */
    gameLogic();
    /*
     * Clears the sequence.
     */
   ~gameLogic();

    /*
     * Add a new number to the sequence between 0 and 1.
     */
    void nextTurn();

    /*
     * A list to hold the sequence of the computer.
     */
    QList<int> sequence;
};

#endif // GAMELOGIC_H
