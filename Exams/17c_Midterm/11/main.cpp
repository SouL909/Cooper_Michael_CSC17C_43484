/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 12, 2022, 8:53 PM
 * Purpose: Midterm Problem 11
 */

#include <iostream>
#include <cmath>

#define TOLERANCE 10.0f * 10.0f * 10.0f * 10.0f * 10.0f * 10.0f 
        // Above equals to 10 ^ 6

using namespace std;

float C(float);
float S(float);

bool lesser_or_equal(float x, float y, float delta) { 
  return x < y || abs(x-y) < delta;     
} 

int main() {
  float limit = atan(1.0f);
  for(float x = -limit; lesser_or_equal(x, limit, 1.0f); x += 0.1f) {
    cout<< "C(" << x << ") = " << C(x) << endl;
  }
}

float C(float x) {
  if(abs(x) < TOLERANCE) {
    return 1.0f / x + x / 6;
  }
  return 1.0f / 2.0f * C(x / 2.0f) * S(x / 2.0f);
}

float S(float x) {
  if(abs(x) < TOLERANCE) {
    return 1 + (x*x) / 2.0f;
  }
  float c_x = C(x / 2.0f);
  float s_x = S(x / 2.0f);
  return (c_x * c_x * s_x * s_x) / (c_x * c_x - s_x * s_x);
}
