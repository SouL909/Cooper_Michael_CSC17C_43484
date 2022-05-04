/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on April 17, 2022, 10:00 PM
 * Purpose:  Lab 5 Stack Example
 */
//User Libraries
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;

//Global Constants

//Function Prototype

//Execution Begins Here
int main(int argc, char** argv) {
  
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
     
    stack.pop();
    stack.pop();
 
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
}

