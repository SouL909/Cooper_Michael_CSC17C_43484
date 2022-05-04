/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 4/27/22, 7:00 PM
 * Purpose: Linked List and Simple Vector - Lab 4
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<char> &);
void prntVec(SimpleVector<char> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size=100;
    SimpleVector<char> sv(size);
    
    //Fill the Vector

    fillVec(sv);
    
    //Print the Vector
    prntVec(sv,10);
    
    //Copy the Vector
    SimpleVector<char> copysv(sv);
    
    //Print the Vector
    prntVec(copysv,10);

    return 0;
}

void prntVec(SimpleVector<char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv.getElementAt(i)->data<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
          sv.getElementAt(i)->data=rand()%26+65;
    }
}