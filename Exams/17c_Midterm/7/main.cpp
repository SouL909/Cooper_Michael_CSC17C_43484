/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 10, 2022, 11:00 AM
 * Purpose: Midterm Problem 7
 */
#include <iostream>
#include <array>
#include <cmath>
#include <random>

using namespace std;

struct Card {
  int value;
  int type;
};

unsigned nCk( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int rand_int(int min, int max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min,max);
  return dist(rng);
}

array<Card, 5> hand() {
  array<Card,5> _hand;
  for(int i = 0; i < 5; i++) {
    Card card;
    card.value = rand_int(1,13);
    card.type = rand_int(1,4);
    _hand[i] = card;
  }
  return _hand;
}

bool is_one_pair(array<Card, 5>& _hand) {


  bool rank2 = false;
  
  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      if(_hand[i].type == _hand[j].type)
        rank2 = true;
    }
  }
  if(!rank2) return rank2;
  rank2 = false;
  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      for(int k = 2; k < j; k++) {
        if(_hand[i].type != _hand[j].type && _hand[k].type != _hand[j].type)
          rank2 = true;
      }
    }
  }

  return rank2;
}

bool is_two_pair(array<Card, 5>& _hand) {
  bool rank2 = false;
  
  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      if(_hand[i].type == _hand[j].type)
        rank2 = true;
    }
  }
  if(!rank2) return rank2;

  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      if(_hand[i].type != _hand[j].type && _hand[i].value == _hand[j].value)
        rank2 = true;
    }
  }
  
  return rank2;
}

bool is_three(array<Card, 5>& _hand) {
  bool rank2 = false;
  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      for(int k = 2; k < j; k++) {
        if(_hand[i].type == _hand[j].type && _hand[k].type == _hand[j].type)
          rank2 = true;
      }
    }
  }
  if(!rank2) return rank2;
  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      if(_hand[i].type != _hand[j].type)
        rank2 = true;
    }
  }
  return rank2;
}

bool is_four(array<Card, 5>& _hand) {
  bool rank2 = false;
  for(int i = 0; i < 5; i++) {
    for(int j = 1; j < i; j++) {
      for(int k = 2; k < j; k++) {
        for(int l = 3; l < k; l++) {
          if(_hand[i].type == _hand[j].type && _hand[j].type == _hand[k].type  &&  _hand[k].type == _hand[l].type)
            rank2 = true;
        }
    }
  }
}
  return rank2;
}

int main() {
  float four_of_a_kind = static_cast<float>(nCk(13,1) * nCk(12,1) * nCk(4,1))/ static_cast<float>(nCk(52,5));
  cout << four_of_a_kind << endl;
  float three_of_a_kind = static_cast<float>(nCk(13,1) * nCk(12,2) * nCk(4,3)* nCk(4,1)* nCk(4,1))/ static_cast<float>(nCk(52,5));
  cout << three_of_a_kind << endl;
  float two_pair = static_cast<float>(nCk(13,1) * nCk(11,1)* nCk(4,2) * nCk(4,2) * nCk(4,1))/ static_cast<float>(nCk(52,5));
  cout << two_pair << endl;
  float one_pair = static_cast<float>(nCk(13,1) * nCk(12,3)* nCk(4,2)* nCk(4,1) * nCk(4,1) * nCk(4,1))/ static_cast<float>(nCk(52,5));
  cout << one_pair << endl;

  array<Card,5> _hand = hand();
  cout << "One Pair: " <<  (is_one_pair(_hand) ? "True" : "False") << endl;
  _hand = hand();
  cout << "Two Pair: " <<  (is_two_pair(_hand) ? "True" : "False") << endl;
  _hand = hand();
  cout << "Three of a kind: " <<  (is_three(_hand) ? "True" : "False") << endl;
  _hand = hand();
  cout << "Four of a kind: " <<  (is_four(_hand) ? "True" : "False") << endl;
}