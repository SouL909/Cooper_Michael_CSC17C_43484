/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 24, 2022, 12:30 PM
 * Purpose: Hashing Assignment - Binary Search
 */

#include <iostream>
#include <string>
#include <chrono>

using namespace std;

static const int SIZE = 10;

void bubbleSort(string arr[], int n = SIZE);
void print(string arr[], int n = SIZE);
int binarySearch(string arr[], string val, int n = SIZE);

int main() {
  string arr[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
  bubbleSort(arr);
  print(arr);
  auto begin = std::chrono::steady_clock::now();
  int i = binarySearch(arr, "six");
  auto end = std::chrono::steady_clock::now();
  cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds." <<endl;
  if(i != -1)
    cout << "Found six at " << i << endl;
}

void bubbleSort(string arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void print(string arr[], int n) {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
  cout << endl;
}

int binarySearch(string arr[], string val, int n) {
    int lowEnd=0;
    int highEnd=n-1;
    
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==arr[middle])return middle;
        else if(val>arr[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}