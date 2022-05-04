/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on April 17, 2022, 9:00 PM
 * Purpose:  Lab 5 List Example
 */

//User Libraries
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <time.h>
#include <random>
#include <chrono>
#include <stdio.h>
#include <array>

using namespace std;

//Global Constants


//Function Prototype
list<int> randList(int n) {
    list<int> l;
    for(int i = 0; i < n; i++) {
        l.push_back(rand() % n + 1);
    }
    return l;
}
void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
//Execution Begins Here
int main(int argc, char** argv) {

    list<int> gqlist1, gqlist2;
  
    for (int i = 0; i < 10; ++i) {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }
    cout << "\nList 1 (gqlist1) is : ";
    showlist(gqlist1);
  
    cout << "\nList 2 (gqlist2) is : ";
    showlist(gqlist2);
  
    cout << "\ngqlist1.front() : " << gqlist1.front();
    cout << "\ngqlist1.back() : " << gqlist1.back();
  
    cout << "\ngqlist1.pop_front() : ";
    gqlist1.pop_front();
    showlist(gqlist1);
  
    cout << "\ngqlist2.pop_back() : ";
    gqlist2.pop_back();
    showlist(gqlist2);
  
    cout << "\ngqlist1.reverse() : ";
    gqlist1.reverse();
    showlist(gqlist1);
  
    cout << "\ngqlist2.sort(): ";
    gqlist2.sort();
    showlist(gqlist2);
  
    list<int> gqlist3 = randList(10);
    cout<<"\nList 3 (gqlist3) is: ";
    showlist(gqlist3);

    cout << "\ngqlist3.sort(): ";
    gqlist3.sort();
    showlist(gqlist3);

    cout <<"\ngqlist3 shuffle: ";
    vector<int> temp(gqlist3.begin(), gqlist3.end());
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (temp.begin(), temp.end(), std::default_random_engine(seed));
    gqlist3.assign(temp.begin(), temp.end());
    showlist(gqlist3);
    return 0;
}
