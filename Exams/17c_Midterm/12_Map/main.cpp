/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 12, 2022, 8:53 PM
 * Purpose: Midterm Problem 12 (Map)
 */

#include <iostream>
#include <map>
#include <deque>
#include <utility>

using namespace std;

void fillMap(map<int,int>& map, int size, int modNum);
deque<int> mode(map<int, int>& map);

int main() {
  int size = 15;
  int modNum = 10;
  map<int,int> mp;
  fillMap(mp, size, modNum);
  auto modeAry = mode(mp);
  cout<<"The number of modes = "<< modeAry[0]<<endl;
  cout<<"The max Frequency = "<< modeAry[1]<<endl;
  if(modeAry[0]==0){
    cout<<"The mode set = {null}"<<endl;
  }
  cout<<"The mode set = {";
  for(int i = 2; i < modeAry.size(); i++)
    cout << modeAry[i] << ",";
  cout << "}"<< endl;
  return 0;
}

deque<int> mode(map<int, int>& mp) {
  deque<int> mod;
  int maxFreq = 0;
  for(auto el : mp) {
    if(maxFreq < el.second)
      maxFreq = el.second;
  }
  int nModes = 0;
  for(auto el : mp) {
    if(maxFreq == el.second) {
      nModes++;
      mod.push_back(el.first);
    }
  }
  mod.push_front(maxFreq);
  mod.push_front(nModes);
  return mod;
}

void fillMap(map<int,int>& mp, int size, int modNum) {
  for(int i=0;i<size;i++){
      auto itr = mp.find(i%modNum);
      if(itr != mp.cend()) {
        mp[itr->first] = mp[itr->first]+1;
      } else {
        mp.insert(make_pair(i%modNum, 1));
      }
  }
}
