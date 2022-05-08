/* 
 * File:   Board.cpp
 * Author: Michael Cooper
 * Purpose: Board Source File
 * Created on 5/1/22
 */

#include "Board.h"

#include <set>
#include <iterator>
#include <iostream>

using namespace std;

std::array<char,3> TEMP = {'#', 'x', 'o'};

std::set<char> MARKERS(TEMP.begin(), TEMP.end());

static std::map<string, char>* _player_markers = nullptr;

// Function for stl for_each for assigning the proper
// information to all players for the board
bool fe(const Player& player) {
  static int li = 2;
  _player_markers->insert(std::pair<string, char>(player.getName(), *(next(MARKERS.cbegin(),li)))); // MARKERS.cbegin() is bidirectional
  li++;
  li % 3 == 0? li = 1: li*=1;
  return true;
}

// Constructor for the board
Board::Board(const std::list<Player>& players) {
  _player_markers = &player_markers;
  for_each(players.cbegin(), 
    players.cend(), fe);
  _player_markers = nullptr;
  board.resize(BOARD_SIZE);
  fill(board.begin(), 
    board.end(), *MARKERS.cbegin()); // Mutating Algorithm: fill()
}

// Checks if the user can mark the board
// and checks the far most bottom of
// a column
bool Board::mark(string name, int col) {
  if(col < 0 && col >= 8) {
    return false;
  }
  for(std::map<string, char>::iterator itr = player_markers.begin(); 
    itr != player_markers.end(); itr++) { // itr is bidirectional
    if(itr->first == name) {
      for(int i = 3; i >= 0; i--) {
        auto spot = next(board.begin(), (col + 8 * i));
        if(*spot != '#')
          continue;
        else {
          *spot = itr->second;
          break;
        }
      }
      return true;
    }
  }
  return false;
}

// iterates through the board and
// prints each element by a 8x4 grid
void Board::printBoard() {
  int i = 0;
  for(auto itr = board.begin(); itr != board.end(); itr++) {
    if(i % 8 == 0)
      cout << endl;
    cout<<*itr << " ";
    i++;
  }
}

// Checks if a player has won in the
// horiztonal direction
char Board::hortWin() {
  int i = 0;
  char prev = *board.begin();
  for(auto itr = next(board.begin(),1); 
    itr != board.end(); itr++) {
    if(prev == *itr && prev != '#') {
        i++;
      }
    else
        i = 0;
    if(i == 3)
    {
      return prev;
    }
    prev = *itr;
  }
  return '#';
}

// Checks if a player has won in the
// vertical direction
char Board::vertWin() {
  int i = 0;
  char prev = '#';
  for(auto itr = board.begin(); 
    itr != board.end(); itr++) {
    prev = *itr;
    for(int i = 3; i >= 0; i--) {
        auto spot = next(itr,  8 * i);
        if(prev == *spot)
          i++;
        else
          i = 0;
      if(i == 4)
      {
        return prev;
      }
      prev = *spot;
    }
  }
  return '#';
}

// Helper function to return
// marker at board position
char markerAt(std::list<char>& board, int i) {
  return *next(board.begin(), i);
}

// Checks if a player has won from a
// a diagonal direction going from
// left to right and right to left
// from the board
char Board::diagWin() {
  int l = 0;
  char prev = '#';
  //descending from the left to right
  // Example: 
  /*
  # # # # # * # # #  Step 4
  # # # # # # * # #  Step 3
  # # # # # # # * #  Step 2
  # # # # # # # # *  Step 1
  */
  for(int i = 0; i <= 5; i++) {  
    for(int j = 0; j < 4; j++) {
      if(markerAt(board, i + 8*j) == '#')
        break;
      if(prev == markerAt(board, i+8*j))
        l++;
      else
        l = 0;
      if(i == 4)
        return prev;
    }
  }
  l = 0;
  prev = '#';
  // ascending the right to left
  // Example: 
  /*
  # # # x # # # # #  Step 1
  # # x # # # # # #  Step 2
  # x # # # # # # #  Step 3
  x # # # # # # # #  Step 4
  */
  for(int i = 7; i >=4; i--) { 
    for(int j = 3; j >= 0; j--) {
      if(markerAt(board, i + 8*j) == '#')
        break;
      if(prev == markerAt(board, i+8*j))
        l++;
      else
        l = 0;
      if(i == 4)
        return prev;
    }
  }
  return '#';
}

// Checks for every case 
// for a win
char Board::win() {
  char c = '#';
  c = vertWin();

  if(c != '#')
    return c;
  c = hortWin();

  if(c != '#')
    return c;
  c = diagWin();

  return c;
}