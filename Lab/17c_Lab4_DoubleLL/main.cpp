/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 4/27/22, 7:00 PM
 * Purpose: Doubly Linked List
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SortedLink.h"
#include "PriortyLink.h"
//Global Constants
using namespace std;
//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {

  SortedLinkedList<int> l;

  l.push(10);
  l.push(1);
  l.push(2);
  l.push(3);

  l.prntLst();

  cout << endl;
  
  PriorityLinedList<int> p;

  p.push_back(10);
  p.push_back(20);
  p.push_back(30);

  p.prntLst();

  cout << endl;
  
  p.find(30);

  p.prntLst();

  return 0;
}