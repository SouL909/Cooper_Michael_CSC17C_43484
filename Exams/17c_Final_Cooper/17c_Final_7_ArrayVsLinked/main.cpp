/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 10, 2022, 6:00 PM
 * Purpose: Final: Problem 7 Arrays Vs Linked List
 */

//System Libraries
#include <iostream>
#include "SimpleVector.h"
#include <chrono>
#include <fstream>
#include <vector>
using namespace std;

//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
  SimpleVector<int> vec;
  int Oi, Os, Of;
  vector<int> datavec;
  for(int i = 0; i < 100; i++) {
    int rSize=rand()%10;
    auto begin = std::chrono::steady_clock::now();
    vec.push(rSize, Oi, Os, Of);
    auto end = std::chrono::steady_clock::now();
    datavec.push_back(i+1);
    datavec.push_back(Oi);
    datavec.push_back(Os);
    datavec.push_back(Of);
    datavec.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count());
  }

  ofstream data;
  data.open("data.txt");
  for(int i = 0; i < datavec.size(); i+=5) {
      data << datavec[i] <<
      " " << datavec[i+1] << 
      " " << datavec[i+2] <<
      " " << datavec[i+3] <<
      " " << datavec[i+4] << endl;
    }
    data.close();
    
    //Exit*/
    return 0;
}