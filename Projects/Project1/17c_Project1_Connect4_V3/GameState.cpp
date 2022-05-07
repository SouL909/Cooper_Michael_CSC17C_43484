/* 
 * File:   GameState.cpp
 * Author: Michael Cooper
 * Purpose: Game State Source File
 * Created on 4/29/22
 */

#include "GameState.h"
#include "Board.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void print_menu() {
  std::cout << "Welcome to Connect 4!" << endl;
  std::cout << "Enter the following options..." << endl;

  std::cout << "1. Rules" << endl;
  std::cout << "2. Play" << endl;
  std::cout << "3. Exit" << endl;
}

MenuState::MenuState(Game* game) {
  this->game = game;
}

void MenuState::run() {
  while (true) {
    print_menu();
    string soption;
    int option = 3;
    getline(cin,soption);
    option = stoi(soption);
    if (option == 1) {
      game->gameState.push(new RuleState(game));
      game->gameState.top()->run();
    } else if(option == 2) {
      game->gameState.push(new CreateState(game));
      game->gameState.top()->run();
    } else {
      std::cout << "\nGoodbye!" << endl;
      break;
    }
  }
  game->gameState.pop();
}

RuleState::RuleState(Game* game) {
  this->game = game;
}

void RuleState::run() {
  cout << "Welcome to Connect 4!\nHere are the rules." << endl;
  cout << "In order for any player can win they must meet the following conditions"<<endl;
  cout << "A player must reach 4 spots diagonally\n";
  cout << "###x####"<<endl;
  cout << "##xo####" << endl;
  cout << "#xoo####" << endl;
  cout << "xooo####" << endl;
  cout << "A player must reach 4 spots horizontally\n";
  cout << "########"<<endl;
  cout << "########" << endl;
  cout << "#xxxx###" << endl;
  cout << "#ooox###" << endl;
  cout << "A player must reach 4 spots vertically\n";
  cout << "#x######"<<endl;
  cout << "#x######" << endl;
  cout << "#x######" << endl;
  cout << "#xooo###" << endl;
  game->gameState.pop();
}

CreateState::CreateState(Game* game) {
  this->game = game;
}

bool comp(const Player& a, const Player& b) {
  return a.getWins() > b.getWins();
}

void CreateState::run() {
  while(true) {
    if(game->players.size() == 0) {
      string name;
      cout << "Enter Player's 1 name: ";
      getline(cin, name);
      game->players.push_back(Player(name));
      cout << "Enter Player's 2 name: ";
      getline(cin, name);
      game->players.push_back(Player(name));
    } else {
      vector<Player> players(game->players.begin(), game->players.end());
      sort(players.begin(), players.end(), comp);
      game->players = list<Player>(players.begin(), players.end());
      for(auto player: players) {
        cout << "Player: " << player.getName() << " Wins: " << player.getWins() << endl;
      }
    }
    game->gameState.push(new PlayState(game));
    game->gameState.top()->run();
    cout << "Play again? (y/n): ";
    string option;
    getline(cin, option);
    if(option == "n") {
      break;
    }
  }
  game->gameState.pop();
}

PlayState::PlayState(Game* game) {
  this->game = game;
}

void PlayState::run() {
  Board board(game->players);
  int rounds = 1;
  const int MAX_ROUNDS = 32;
  cout<<"Playing..."<<endl;
  bool running = true;
  while(running) {
    queue<Player*> players;
    for(auto& player: game->players) {
      players.push(&player);
    }
    
    while(!players.empty()) {
      auto player = players.front();
      if(rounds > MAX_ROUNDS) {
        cout << "No one won ... \n";
        break;
      }
      board.printBoard();
      cout << player->getName() <<"\'s turn!" <<endl;
      cout << "Enter a number from 0-7\n";
      string option;
      getline(cin,option);
      int opt = stoi(option);
      board.mark(player->getName(), opt);
      char c = board.win();
      if(c != '#') {
        cout << player->getName() << " WINS!" << endl;
        player->setWins(player->getWins() + 1);
        running = false;
        break;
      }
      rounds++;
      player = players.front();
      players.pop();
    }
  }
  game->gameState.pop();
}