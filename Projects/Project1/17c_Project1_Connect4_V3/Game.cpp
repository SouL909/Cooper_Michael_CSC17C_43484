/* 
 * File:   Game.cpp
 * Author: Michael Cooper
 * Purpose: Game Source File
 * Created on 4/30/22
 */

#include "Game.h"
#include "GameState.h"

using namespace std;

Game::Game() {
  
}

// Should only be called once!
//Starting the game passes menu state into game state
void Game::start() {
  GameState* menu = new MenuState(this);
  gameState.push(menu);
  run();
}

//runs state from top of stack
void Game::run() {
  gameState.top()->run();
}
