/* 
 * File:   Player.cpp
 * Author: Michael Cooper
 * Purpose: Player Source File
 * Created on 6/11/22
 */

#include "Player.h"
#include <iostream>

using namespace std;

// Constructors
Player::Player(string name) {
  this->name = name;
  wins = 0;
}

Player::Player(string name, int wins) {
  this->name = name;
  this->wins = wins;
}

Player::Player(const Player& player) {
  name = player.getName();
  wins = player.getWins();
}

// Getters
std::string Player::getName() const { 
  return name; 
}

int Player::getWins() const { 
  return wins; 
}

// Setters
void Player::setName(std::string name) { 
  this->name = name; 
}

void Player::setWins(int wins) { 
  this->wins = wins; 
}

// Used for saving player
// data into the save file
string Player::data() {
  return name + "\n" + to_string(wins);
}

// Used to check player input
// for marking the board
int Player::getInput() {
  while(true) {
    cout << getName() <<"\'s turn!" <<endl;
    cout << "Enter a number from 0-7\n";
    string option;
    getline(cin,option);
    int opt = stoi(option);
    if(opt < 0 && opt > 7) {
      cout << "That is not a valid option!" << endl;
      cout << "Option has to between 0 and 7" << endl;
      continue;
    }
    return opt;
  }
}
