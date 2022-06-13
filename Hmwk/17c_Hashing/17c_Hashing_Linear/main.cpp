/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 22, 2022, 2:53 PM
 * Purpose: Hashing Assignment - Linear Search
 */

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

static const int SIZE = 10;

int linearSearch(const string* arr, string val, int size = SIZE);

int main() {
  string arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
  
  auto begin = std::chrono::steady_clock::now();
  int i = linearSearch(arr, "eight");
  auto end = std::chrono::steady_clock::now();
  cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds." <<endl;
  
  if(i >= 0) {
    cout << "Found eight" << endl;
  }
  begin = std::chrono::steady_clock::now();
  i = linearSearch(arr, "eight");
  end = std::chrono::steady_clock::now();
  cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds." <<endl;
  if(i == -1) {
    cout << "Did not find twenty one" << endl;
  }
}

int linearSearch(const string* arr, string val, int size) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == val)
      return i;
  }
  return -1;
}