/* 
 * File:   GameState.cpp
 * Author: Michael Cooper
 * Purpose: Game State Source File
 * Created on 6/11/22
 */

#include "GameState.h"
#include "Board.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <deque>
#include "Tree.h"
#include "Graph.h"
using namespace std;


bool comp(const Player& a, const Player& b) {
  return a.getWins() < b.getWins();
}

void swap(Player* x, Player* y) {
	Player temp = *x;
	*x = *y;
	*y = temp;
}

// Recursive bubble sort
void rec_bubble(Player arr[], int n) {
	if (n <= 1) return;

	for (int i = 0; i < n - 1; i++) {
		if (comp(arr[i],  arr[i + 1]))
			  swap(&arr[i], &arr[i + 1]);
	}

	rec_bubble(arr, n - 1);
}

// Prints the menu options
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

// Will print all the options the user
// can make and redirect them
// to the appropriate state
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

// Give the player the information
// on how to play the game
void RuleState::run() {
  cout << "Welcome to Connect 4!\nHere are the rules." << endl;
  cout << "Players will go turn by turn adding their marker to the board." << endl;
  cout << "and in order for any player can win they must meet the following conditions"<<endl;
  
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

  std::cout << "Enter the following options..." << endl;

  std::cout << "1. Play" << endl;
  std::cout << "2. Return to Menu" << endl;
  
  string soption;
  int option = 3;
  
  getline(cin,soption);
  option = stoi(soption);
  
  if (option == 1) {
    game->gameState.push(new CreateState(game));
    game->gameState.top()->run();
  } 
  game->gameState.pop();
}

CreateState::CreateState(Game* game) {
  this->game = game;
}


// Is responsible for making players
// or checking if there are any
// players in the save file
void CreateState::run() {
  Tree<int> player_wins;
  Graph* graph;
  vector<Player> players(game->players.begin(), game->players.end());
  
  ifstream myfile ("players.txt");
  // Checking if there is a save file
  // and if the save file is not empty
  if(myfile.is_open() || myfile.peek() != std::ifstream::traits_type::eof()) {
    string line;
    int i = 0;
    
    deque<string> names;
    deque<int> wins;

    // Goes through the file
    // and searches for names and wins
    while(getline(myfile, line)) {
      if(line.empty()) continue;
      if(i % 2 == 0) {
        names.push_back(line);
      } else {
        wins.push_back(stoi(line));
      }
      i++;
    }

    // Make new players according to the 
    // names and wins found
    vector<Edge> edges;
    for(int i = 0; i < names.size(); i++) {
      players.push_back(Player(names[i], wins[i]));
      player_wins.push(wins[i]);
      edges.push_back(make_edge(names[i],names[(i+1)%names.size()],i,(i+1)%names.size(),wins[i]));
    }
    graph = new Graph(names.size(), edges);
    graph->mst();
  }
  
  myfile.close();

  // Player creation loop if no players
  // were found in the save file
  // or the players chooses to make new players
  while(true) {
    if(players.size() == 0) {
      // No players were loaded from the save file
      string name;
      cout << "Enter Player's 1 name: ";
      getline(cin, name);
      game->players.push_back(Player(name,0));
      cout << "Enter Player's 2 name: ";
      getline(cin, name);
      game->players.push_back(Player(name,0));
    } else {
      // Uses the comp function to sort the
      // players by their win count
      // sort(players.begin(), players.end(), comp);
      rec_bubble(&players[0], players.size());
      // game->players = list<Player>(players.begin(), players.end());
      int i = 0;
      // prints out all the players and assigns a number to them
      cout << "Leaderboards and selection" << endl;
      for(auto player: players) {
        cout << "----------------------------------------------------" << endl;
        cout << "(" << i + 1 << ") "<<"Player: " << player.getName() << " Wins: " << player.getWins() << endl;
        cout << "----------------------------------------------------" << endl;
        i++;
      }

      cout << "Would you like to create new players? (y/n)" << endl;
      string option;
      getline(cin, option);
      if(option == "y") {
        // Players get to choose their player save
        string name;
        cout << "Enter Player's 1 name: ";
        getline(cin, name);
        game->players.push_back(Player(name));
        cout << "Enter Player's 2 name: ";
        getline(cin, name);
        game->players.push_back(Player(name));
      } else {
        // Players get to make new Players to save
        
        cout << "Player 1 select your profile: ";
        getline(cin, option);
        
        Player player = *next(players.begin() , stoi(option) -1);
        
        game->players.push_back(player);

        cout << "Player 2 select your profile: ";
        getline(cin, option);

        player = *next(players.begin() , stoi(option) -1);
         
        game->players.push_back(player);
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
  delete graph;
  game->gameState.pop();
}

PlayState::PlayState(Game* game) {
  this->game = game;
}

// PlayState is responsible
// for all the game logic
void PlayState::run() {
  // Creating board
  Board board(game->players);
  int rounds = 1;
  const int MAX_ROUNDS = 32;
  cout<<"Playing..."<<endl;
  bool running = true;
  while(running) {
    queue<Player*> players;
    // Players go through a queue based
    // turn by turn
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
        board.printBoard();
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

  // Makes a copy of the save file
  // In order to update each player's
  // win counter
  fstream myfile ("players.txt", std::fstream::in | std::fstream::out);
  if(myfile.is_open()) {
    deque<Player> temp;
    string line;
    int i = 0;
    
    deque<string> names;
    deque<int> wins;
    
    // Goes through the file
    // and searches for names and wins
    while(getline(myfile, line)) {
      if(line.empty()) continue;
      if(i % 2 == 0) {
        names.push_back(line);
      } else {
        wins.push_back(stoi(line));
      }
      i++;
      
    }

    for(int i = 0; i < names.size(); i++) {
      temp.push_back(Player(names[i], wins[i]));
    }
    myfile.close();

    // Checks if any of the current players
    // need to update their
    // scores
    for(auto player : game->players) {
      bool found = false;
      for(int i = 0; i < names.size(); i++) {
        if(temp[i].getName()  == player.getName()) {
          temp[i].setWins(player.getWins());
          found = true;
          break;
        }
      }
      // If the player was not found in the copy of
      // the save file then they are a new player
      // and need to be added in the save file
      if(!found) {
        Player nplayer(player.getName(), player.getWins());
        temp.push_back(nplayer);
      }
    }


    myfile.close();
    // Close the the file and open it in output mode
    fstream myfile2 ("players.txt", std::fstream::in | std::fstream::out);
    // Makes sure the file is not empty for formatting issues
    
    if(myfile2.peek() == std::ifstream::traits_type::eof()) {
      bool first = true;

      for(auto player : temp) {
        if(!first) {
          myfile2 << "\n";
        }
        first = false;
        myfile2 << player.data();
      }
    } else {
      for(auto& player : temp) {
        myfile2 << "\n";
        myfile2 << player.data();
      }
    }
    
    myfile2.close();
  }
  // clears all the players from the list
  // in order to not have duplicate players
  // in the save file
  game->players.clear();
  game->gameState.pop();
}