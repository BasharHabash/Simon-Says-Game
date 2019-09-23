#include "gamelogic.h"
#include <cstdlib>

/*
 * Bashar Habash
 * Boden Archuleta
 *
 * Assignment 5; A QT Simon Game
 *
 * The implementation of the computers logic.
 */
gameLogic::gameLogic()
{
    nextTurn();
}

gameLogic::~gameLogic()
{
    sequence.clear();
}

void gameLogic:: nextTurn()
{
    //seeds the RNG
    srand(static_cast<unsigned int>(time(nullptr)));
    sequence.append(rand() % 2);
}
