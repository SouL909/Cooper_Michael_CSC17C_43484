/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 5/5/22, 11:00 AM
 * Purpose: Project 1 - Connect 4 - Version 4 FINAL BUILD
 * Further expanded project with a text output that will keep track of players
 * and their win counts, further optimized and made comments. 
 */

#include "Game.h"
#include "Board.h"

int main() {
  // Initalizes and runs game
  Game game;
  game.start();
  game.run();
}