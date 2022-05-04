/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on April 17, 2022, 10:00 PM
 * Purpose:  Lab 5 Queue Example
 */
//User Libraries
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

//Global Constants

// Print the queue
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
//Execution Begins Here
int main(int argc, char** argv) {
queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
 
    cout << "The queue gquiz is : ";
    showq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);

    return 0;
}