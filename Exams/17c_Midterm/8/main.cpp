/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 14, 2022, 11:00 AM
 * Purpose: Midterm Problem 8
 */

#include <iostream>
#include <bitset>
#include <cmath>
#include <random>

#define N 100
#define S 5

using namespace std;

int randInt();
void fill(bitset<N>&,float);

int main() {
  float probabilty = 0.4f;
  int success = 5;
  cout << "Bit vector is " << probabilty * 100 << 
    "% ; odds of 5 bits to fall into filled section is " << powf(probabilty, 5) * 100 << "%\n";
  cout << "----- Simulation -----" << endl;
  cout << "Bit vector of size 100\n";
  cout << "Bit vector is 40% full\n";
  
  bitset<N> bits;

  int randAry[S];
  int a_success = 0;
  for(int i = 0; i < S; i++) {
    randAry[i] = randInt();
  }

  for(int i = 0; i < S; i++) {
    if(bits[randAry[i]] == 1) {
      a_success++;
    }
  }

  cout << "Successful: " << a_success << endl;
  cout << "Probability: " << static_cast<float>(a_success)/100.0f << endl;
  
}

void fill(bitset<N>& bits, float p) {
  for(int i = 0; i < N; i++) {
    int pt = randInt();
    if (pt <= p * 100.0f) {
      bits[i] = 1;
    } else {
      bits[i] = 0;
    }
  }
}

int randInt() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,99);
  return dist(rng);
}
