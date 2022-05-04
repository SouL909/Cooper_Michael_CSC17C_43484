/*Michael Cooper
  April 20th, 2022
  Purpose:  Curve fit of Data Structure empirical timing and/or
            operational analysis
*/
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries 
#include "mArray.h"

//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

//Execution begins here
int main() {
    //Declare the Row and Empirical Data files
    char fn_r[] = "r2.dat";//r file name
    mArray r(fn_r);     //Independent variable, form of the equation
    char fn_f[] = "f2.dat";//f file name
    mArray f(fn_f);     //Dependent variable, from empirical data run

    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt(false, r); //Transpose of independent variable
    mArray temp = rt * f;   //Calculate from right to left more efficient
    mArray c = mArray::invMat(rt * r) * temp;

    //Output the results
    char fn_c[] = "c2.dat";//c file name
    c.mPrint(fn_c);     //Where curve fit coefficients are printed
    
       //Declare the Row and Empirical Data files
    char fn_r3[] = "r3.dat";//r file name
    mArray r3(fn_r3);     //Independent variable, form of the equation
    char fn_f3[] = "f3.dat";//f file name
    mArray f3(fn_f3);     //Dependent variable, from empirical data run

    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt3(false, r3); //Transpose of independent variable
    mArray temp3 = rt3 * f3;   //Calculate from right to left more efficient
    mArray c3 = mArray::invMat(rt3 * r3) * temp3;

    //Output the results
    char fn_c3[] = "c3.dat";//c file name
    c3.mPrint(fn_c3);     //Where curve fit coefficients are printed

    return 0;
}

