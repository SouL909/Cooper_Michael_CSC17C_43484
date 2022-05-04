/* 
 * File:   Game.cpp
 * Author: Michael Cooper
 * Purpose: Board Header File
 * Created on 4/15/22
 */

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <array>
#include <set>      // Associative Container: set
#include <iterator>
#include <map>      // Associate Container: map
#include <list>

#include <algorithm>

#include "Player.h"

const int BOARD_SIZE = 8*4;
//Class declaration, keeps track of each individual tile for X's or O's
//Also keeps track of which player is X or O
class Board {
public:
  std::list<char> board; // Sequences: list
  std::map<std::string, char> player_markers;
  Board(const std::list<Player>& players);
public:
  bool mark(std::string name, int col);
  char vertWin();   
  char hortWin();
  char diagWin();
  char win();
  void printBoard();
};

#endif // BOARD_H
