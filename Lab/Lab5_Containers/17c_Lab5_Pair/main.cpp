/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on April 17, 2022, 8:00 PM
 * Purpose:  Lab 5 Pair Example
 */
//User Libraries
#include <cstdlib>
#include <iostream>
#include <utility>
using namespace std;

//Global Constants

//Function Prototype

//Execution Begins Here
int main(int argc, char** argv) {

    pair<int, char> PAIR1;
    pair<string, double> PAIR2("GeeksForGeeks", 1.23);
    pair<string, double> PAIR3;
    pair<int, int> PAIR4(23, -12);
 
    PAIR1.first = 100;
    PAIR1.second = 'G';
 
    PAIR3 = make_pair("GeeksForGeeks is Best", 4.56);
 
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
 
    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl;
 
    cout << PAIR3.first << " ";
    cout << PAIR3.second << endl;

    cout << PAIR4.first << " ";
    cout << PAIR4.second << endl;

    
    cout << "Max element in Pair 4: " << max(PAIR4.first, PAIR4.second);
    cout << "\nMin element in Pair 4: "<< min(PAIR4.first, PAIR4.second);
    return 0;
}

