/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 5, 2022, 11:30 PM
 * Purpose: Final: Problem 2 Stacks
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int h_calls = 0;
int g_calls = 0;

float h(float);
float g(float);

bool lesser_or_equal(float x, float y, float delta) {             
    return x < y || abs(x - y) < delta;                               
}

int main(int argc, char** argv) {
    ofstream hsin;
    ofstream hsincos;
    hsin.open("hsin.dat");
    hsincos.open("hsincos.dat");
    //Testing out recursive trig functions
    for (float i = -1.0f; lesser_or_equal(i,1.0f, 0.1f); i += 0.1f) {
        h(i);
        hsin << h_calls << endl;
        h_calls = 0;
        g_calls = 0;

    }
    cout << "--------------------------------------" << endl;
    //Testing out recursive trig functions
    for (float i = -1.0f; lesser_or_equal(i, 1.0f, 0.1f); i += 0.1f) {
        h(i)/g(i);
        hsincos << h_calls << " " << g_calls << endl;
        h_calls = 0;
        g_calls = 0;
    }

    hsin.close();
    hsincos.close();
    return 0;
}

float h(float angR) {
    h_calls++;
    float tol = 1e-6;
    if (angR > -tol && angR < tol)return angR + angR * angR * angR / 6;
    return 2 * h(angR / 2) * g(angR / 2);
}
float g(float angR) {
    g_calls++;
    float tol = 1e-6;
    if (angR > -tol && angR < tol)return 1 + angR * angR / 2;
    float b = h(angR / 2);
    return 1 + 2 * b * b;
}
