/* 
 * Author: Michael Cooper
 * Created on April 24th, 2022, 8:00 PM
 * Purpose: Assignment Permutation and Combination Comparison 
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int factorial(int n) {
  if(n == 0) {
    return 1;
  }
  return n * factorial(n-1);
}

int permutation(int n, int m) {
  return factorial(n)/factorial(n-m);
}

int permutation_replace(int n, int m) {
  return pow(n,m);
}

int combination(int n, int m) {
  return (factorial(n)/factorial(n-m))/factorial(m);
}

int combination_replacement(int n, int m) {
  return (factorial(n+m-1)/factorial(n-1))/factorial(m);
}

void print_headers() {
  cout << "P -> Permutation(Order Matters)" << endl;
  cout << "C -> Combination(Order does not matter)" << endl;
  cout << "Rep -> with replacement" << endl;
  cout << "no Rep -> no replacement" << endl;
  cout << "N -> Number of total elements" << endl;
  cout << "M -> Number of elements to take from the total" << endl << endl;
  cout << "N M P Rep P no Rep C Rep C no Rep" << endl;
  cout << "N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)" << endl << endl;
}

void print_table() {
  cout<< left << setw(12) << setfill(' ') << "n";
  cout<< left << setw(12) << setfill(' ') << "m";
  cout<< left << setw(12) << setfill(' ') << "Permutation";
  cout<< left << setw(12) << setfill(' ') << "Permutation";
  cout<< left << setw(12) << setfill(' ') << "Combination";
  cout<< left << setw(12) << setfill(' ') << "Combination";
  cout<< left << setw(12) << setfill(' ') << " ";
  cout<< left << setw(23) << setfill(' ') << " ";
  cout<< left << setw(12) << setfill(' ') << "Replacement";
  cout<< left << setw(12) << setfill(' ') << " ";
  cout<< left << setw(12) << setfill(' ') << "Replacement";
  cout<< left << setw(12) << setfill(' ') << " " << endl;
  for(int n = 2; n <=26; n++) {
    for(int m = 0; m <= n; m++) {
      cout<< left << setw(12) << setfill(' ') << n;
      cout<< left << setw(12) << setfill(' ') << m;
      cout<< left << setw(12) << setfill(' ') << permutation_replace(n,m);
      cout<< left << setw(12) << setfill(' ') << permutation(n, m);
      cout<< left << setw(12) << setfill(' ') << combination_replacement(n, m);
      cout<< left << setw(12) << setfill(' ') << combination(n,m) << endl;
    }
  }
}

int main() {
  print_table();
  return 0;
}