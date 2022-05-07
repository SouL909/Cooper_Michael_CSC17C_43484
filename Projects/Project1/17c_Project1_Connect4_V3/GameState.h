/* 
 * File:   GameState.h
 * Author: Michael Cooper
 * Purpose: Game State Header File
 * Created on 4/29/22
 */


#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class Game;

class GameState {
public:
  virtual void run() = 0;
};

//Keeps track of where the game is relative to the player.
//Is the player in the menu, creating game, or playing/Reading rules?
class MenuState : public GameState {
private:
  Game* game;
public:
  MenuState(Game* game);
  void run();
};

class CreateState : public GameState {
private:
  Game* game;
public:
  CreateState(Game* game);
  void run();
};

class PlayState : public GameState {
private:
  Game* game;
public:
  PlayState(Game* game);
  void run();
};

class RuleState : public GameState {
private:
  Game* game;
public:
  RuleState(Game* game);
  void run();
};
#endif // GAMESTATE_H