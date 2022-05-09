/*
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 5/7/22, 11:00 AM
 * Purpose: Binomial Theorem Lab
 * calculate the probability of flipping a coin 4 times and getting 1 tail and 3 heads.
 */

#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int factorial(int n) {
  if (n == 1) {
    return 1;
  }
  return n * factorial(n-1);
}

int nCk(int n, int k) {
int top = factorial(n);
int bottom = (factorial(k)*factorial(n-k));
  return (top/bottom);
}

float probabilty(int n, int k, float p) {
  return static_cast<float>(nCk(n,k))* powf(p,k) * powf((1.0f - p), n-k);
}

int rand_int(int min, int max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(min,max);
  return dist(rng);
}

int main() {
  cout << "Probabilty of coin flip" << endl;
  cout << ">> 4 repeated trials, 3 heads, 1 tails " << endl;
  cout << ">> >> Probabilty of heads: "<< probabilty(4.0f, 3.0f, 0.5f) << endl;
  cout << ">> >> Probabilty of tails: "<< probabilty(4.0f, 1.0f, 0.5f) << endl;

  int success = 0;  // Success represent the amount of time heads was flipped
  for(int i = 0; i < 10; i++) {
    int rng = rand_int(1,2);  // 1 for heads, 2 for tails
    if(rng == 1) {
      success++;
    }
  }

  cout << endl;
  
  float succes_percent = static_cast<float>(success) / 10.0f;
  float failure_precent = 1.0f - static_cast<float>(success) / 10.0f;
  cout << "Results of 10 coin flips: " << endl;
  cout << "Heads: " << succes_percent <<  " Tails: " << failure_precent << endl;

  cout << endl;
  
  cout << "Probabilty of biased coin flip (p=0.6, biased towards head)" << endl;
  cout << ">> 10 repeated trials, " << success << " heads, " << 10-success << " tails " << endl;
  cout << ">> >> Probabilty of heads: "<< to_string(probabilty(10, success, 0.6)) << endl;
  cout << ">> >> Probabilty of tails: "<< to_string(probabilty(10, 10 - success, 0.4)) << endl;
  
  return 0;
}
