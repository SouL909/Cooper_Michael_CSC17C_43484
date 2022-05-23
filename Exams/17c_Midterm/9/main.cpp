/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 10, 2022, 1:00 PM
 * Purpose: Midterm Problem 9
 */

#include <iostream>
#include <cmath>

using namespace std;

float y(float x, unsigned int n) {
  if(n == 0)
    return 1;
  else
    return x * y(x, n- 1);
}

float y1(float x, unsigned int n) {
  if(n == 0)
    return 1;
  if (n == 1)
    return x;
  int c = 0;
  if(n % 2 == 1) {
    c = (n - 1) / 2;
  } else {
    c = n / 2;
  }
  float product = x;
  for(int i = 1; i < c; i++)
    product *= x;
  product*= product;
  if(n % 2 == 1)
    product *= x;
  return product;
}

int main() {
  for(int i = 0; i < 10; i++)
    cout<< i << "\t" << y(2, i) << "\t" << y1(2, i) << "\n";
}