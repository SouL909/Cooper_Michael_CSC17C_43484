/* 
 * File:   Player.cpp
 * Author: Michael Cooper
 * Purpose: Player Source File
 * Created on 4/28/22
 */

#include "Player.h"

using namespace std;
//Assigns names to wins
Player::Player(string name, int wins) {
  this->name = name;
  this->wins = wins;
}

Player::Player(const Player& player) {
  name = player.getName();
  wins = player.getWins();
}

//Getters and setters
std::string Player::getName() const { return name; }
int Player::getWins() const { return wins; }

void Player::setName(std::string name) { this->name = name; }
void Player::setWins(int wins) { this->wins = wins; };

