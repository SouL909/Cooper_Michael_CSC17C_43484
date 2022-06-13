/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 6/8/22, 12:00 PM
 * Purpose: Project 2 - Connect 4 - Version 2
 * Finished header files for hash and tree inclusion. This build does not yet run
 */

#include <cstdlib>
#include "Game.h"
#include "Board.h"

using namespace std;

int main(int argc, char** argv) {
 // Initializes and runs game
  Game game;
  game.start();
  game.run();
    return 0;
}

