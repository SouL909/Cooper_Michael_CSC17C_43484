/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 6/12/22, 8:00 AM
 * Purpose: Project 2 - Connect 4 - Version 3 FINAL BUILD
 * Completed Source files necessary for build to run
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

