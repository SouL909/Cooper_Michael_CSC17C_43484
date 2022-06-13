/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 6/5/22, 11:00 AM
 * Purpose: Project 2 - Connect 4 - Version 1
 * Started creating header files based on last project and started adding 
 * recursive and graph ideas. Build does not yet run
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

