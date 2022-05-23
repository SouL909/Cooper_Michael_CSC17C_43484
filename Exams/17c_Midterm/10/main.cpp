/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 12, 2022, 2:53 PM
 * Purpose: Midterm Problem 10
 */

#include <iostream>
#include <cmath>

#define TOLERANCE 10.0f * 10.0f * 10.0f * 10.0f * 10.0f * 10.0f 
        // ^^ 10 ^ 6
using namespace std;

float g(float x) {
  if(abs(x) < TOLERANCE) {
    return x - (x * x * x)/6.0f;
  }
  float g_x = g(x/2.0f);
  return 2.0f*g_x/(1 + g_x * g_x);
}

bool lesser_or_equal(float x, float y, float delta) {   
// added so x is in [-1, 1] rather than x in [-1, 1) due to a limitation of floating point
  return x < y || abs(x-y) < delta;                                
}                   
                                                                  
int main() {
  for(float x = -1.0f; lesser_or_equal(x, 1.0f, 0.1f); x+=0.1f)    
    cout<< "g(" << x << ") = " << g(x) << endl;
}