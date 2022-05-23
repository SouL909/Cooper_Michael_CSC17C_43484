/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 117, 2022, 1:00 PM
 * Purpose: Midterm Problem 1
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

int Oi = 0; 
int Os = 0;

int linSrch(int [],int, int);
void clearO();
void fillAry(int [],int,int,int);
void prntAry(int *,int,int);

int main() {
  int size = 10;
  int perline = 10;
  int lowRng=100,highRng=200;
  ofstream data;
  data.open("data.txt");
  for(int i = size; i <= 10000; i+=10) {
    int* arr = new int[i];
    fillAry(arr,i,highRng,lowRng);
    int value=rand()%(highRng-lowRng+1)+lowRng;
    auto begin = std::chrono::steady_clock::now();
    linSrch(arr,i,value);
    auto end = std::chrono::steady_clock::now();
    cout << " ----------------------------------------- " << endl;
    cout << "N = " << i << endl;
    cout << "Oi = " << Oi << endl;
    cout << "Os = " << Os << endl;
    cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds." <<endl;
    data << i <<
    " " << Oi << 
    " " << Os <<
    " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;
    cout << " ----------------------------------------- " << endl;
    delete [] arr;
  }
  data.close();
}

int  linSrch(int a[],int n, int val){
    for(int indx=0;indx<n;indx++){
        Oi+=5;
        if(val==a[indx]) {
          Os+=3;
          return indx;
        }
    }
    return -1;
}

void clearO() {
  Oi = 0;
  Os = 0;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}
