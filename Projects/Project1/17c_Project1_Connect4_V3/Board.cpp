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

//Because I have an older version of C++ running on mac, I had to keep track of the markers this way for the build to run.
std::array<char,3> TEMP = {'#', 'x', 'o'};

std::set<char> MARKERS(TEMP.begin(), TEMP.end());

static std::map<string, char>* _player_markers = nullptr;

//How to determine which player is which, goes through the map to assign X or O to player name
bool fe(const Player& player) {
  static int li = 2;
  _player_markers->insert(std::pair<string, char>(player.getName(), *(next(MARKERS.cbegin(),li)))); // MARKERS.cbegin() is bidirectional
  li++;
  li % 3 == 0? li = 1: li*=1;
  return true;
}

//Constructor to create board
Board::Board(const std::list<Player>& players) {
  _player_markers = &player_markers;
  for_each(players.cbegin(), players.cend(), fe);
  _player_markers = nullptr;
  board.resize(BOARD_SIZE);
  fill(board.begin(), board.end(), *MARKERS.cbegin()); // Mutating Algorithm: fill()
}

//Checks each column of array and sees where it can place marker
bool Board::mark(string name, int col) {
  if(col < 0 && col >= 8) {
    return false;
  }
  for(std::map<string, char>::iterator itr = player_markers.begin(); itr != player_markers.end(); itr++) { // itr is bidirectional
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

//Showing board as markers are assigned
void Board::printBoard() {
  int i = 0;
  for(auto itr = board.begin(); itr != board.end(); itr++) {
    if(i % 8 == 0)
      cout << endl;
    cout<<*itr << " ";
    i++;
  }
}

//Checks for win case in horizontal direction
char Board::hortWin() {
  int i = 0;
  char prev = *board.begin();
  for(auto itr = next(board.begin(),1); itr != board.end(); itr++) {
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

//Checks for win case in horizontal direction
char Board::vertWin() {
  int i = 0;
  char prev = '#';
  for(auto itr = board.begin(); itr != board.end(); itr++) {
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

//Shorthand to get character on its place on the board
char markerAt(std::list<char>& board, int i) {
  return *next(board.begin(), i);
}

////Checks for win case in diagonal direction
char Board::diagWin() {
  int l = 0;
  char prev = '#';
  for(int i = 0; i <= 5; i++) {  //descending
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
  for(int i = 7; i >=4; i--) { //ascending
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

//Checks for wins in all directions
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