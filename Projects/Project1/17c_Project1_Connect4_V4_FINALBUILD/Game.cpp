/* 
 * File:   Game.cpp
 * Author: Michael Cooper
 * Purpose: Game Source File
 * Created on 4/30/22
 */

#include "Game.h"
#include "GameState.h"

using namespace std;

//Constructor
Game::Game() {
  
}

// Deconstructor
Game::~Game() {
  
}

// Should only be called once!
void Game::start() {
  GameState* menu = new MenuState(this);
  gameState.push(menu);
}

void Game::run() {
  gameState.top()->run();
}