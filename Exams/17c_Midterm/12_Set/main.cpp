/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 12, 2022, 8:53 PM
 * Purpose: Midterm Problem 12 (Set)
 */

#include <iostream>
#include <ctime>
#include <set>
#include <deque>

using namespace std;

set<int> fillAry(set<int>& mode, deque<int>& modeAry, int size, int modNum);

int main() {
  int size = 15;
  int modNum = 10;
  set<int> mode;
  deque<int> modeAry;

  set<int> results = fillAry(mode, modeAry, size, modNum);
  
  cout<<"The number of modes = "<< modeAry[0]<<endl;
  cout<<"The max Frequency = "<< modeAry[1]<<endl;
  if(modeAry[0]==0){
    cout<<"The mode set = {null}"<<endl;
  }
  cout<<"The mode set = {";
  for(auto el : results)
    cout << el << ",";
  cout << "}"<< endl;
  return 0;
}

set<int> fillAry(set<int>& mode, deque<int>& modeAry, int size, int modNum) {
  set<int> results;
  int maxFreq = 0;
  modeAry.resize(size);
  for(int i =0; i < size; i++) {
    if(!mode.insert(i%modNum).second) {
      modeAry[i%modNum]++;
      if(maxFreq < modeAry[i%modNum]) {
        maxFreq = modeAry[i%modNum];
      }
    }
  } 
  int nModes = 0;
  for(int i = 0; i < size; i++) {
    if(maxFreq == modeAry[i]) {
      nModes++;
      results.insert(*next(mode.begin(), i));
    }
  }

  modeAry.push_front(maxFreq+1);
  modeAry.push_front(nModes);
  
  return results;
}