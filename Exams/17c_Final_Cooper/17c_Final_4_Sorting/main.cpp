/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 8, 2022, 9:00 AM
 * Purpose: Final: Problem 4 Sorting
 */

#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;

const int MAX = 100000;

int P_M = 8;
int P_S = 8;
int Oi = 0;
int Os = 0;
int Of = 0;
int Op = 0;

short rand_int();

void fill(short* arr, int n = MAX);

void swap(short* xp, short* yp);
void printArray(short A[], int size = MAX);
void merge(short* array, int const left, int const mid, int const right, int n = MAX);
void merge_sort(short* arr, int const begin, int const end, int p_m = 0, int n = MAX);
void selection_sort(short* arr, int p_m = 0, int n = MAX);

int main(int argc, char** argv) {
    short* arr = new short[MAX];
    ofstream data;
    data.open("data.txt");
    fill(arr);
    for (int i = 10; i <= 1000; i += P_M) {
        auto begin = std::chrono::steady_clock::now();
        merge_sort(arr, 0, MAX - 1);
        auto end = std::chrono::steady_clock::now();
        cout << " ----------------------------------------- " << endl;
        cout << "N = " << i << endl;
        cout << "Oi = " << Oi << endl;
        cout << "Os = " << Os << endl;
        cout << "Op = " << Op << endl;
        cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds." << endl;
        data << i <<
            " " << Oi <<
            " " << Os <<
            " " << Op <<
            " " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
        cout << " ----------------------------------------- " << endl;
        Oi = 0;
        Os = 0;
        Of = 0;
        Op = 0;
    }
    short* arr2 = new short[MAX];
    fill(arr2);
    data.close();
    data.open("data2.txt");
    for (int i = 10; i <= 1000; i += P_M) {
        auto begin = std::chrono::steady_clock::now();
        selection_sort(arr2, 0, MAX - 1);
        auto end = std::chrono::steady_clock::now();
        cout << " ----------------------------------------- " << endl;
        cout << "N = " << i << endl;
        cout << "Oi = " << Oi << endl;
        cout << "Os = " << Os << endl;
        cout << "Op = " << Op << endl;
        cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds." << endl;
        data << i <<
            " " << Oi <<
            " " << Os <<
            " " << Op <<
            " " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << endl;
        cout << " ----------------------------------------- " << endl;
        Oi = 0;
        Os = 0;
        Of = 0;
        Op = 0;
    }
    delete[] arr;
	return 0;
}

short rand_int() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(1, 100);

    return dist(rng);
}

void fill(short* arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand_int();
}

void swap(short* xp, short* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void merge_sort(short* arr, int const begin, int const end,int p_m, int n) {
    if (p_m == P_M) {
        cout << p_m << endl;
        return;
    }
    if (begin >= end)
        return; // Returns recursively
    
    auto mid = begin + (end - begin) / 2;
    merge_sort(arr, begin, mid, p_m+1);
    merge_sort(arr, mid + 1, end, p_m + 1);
    merge(arr, begin, mid, end);
    Oi += 12;
}

void selection_sort(short* arr, int p_m, int n) {
 
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                Op += 3;
            }
            Os += 8;
        }
        if (p_m == P_S) return;
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
        Oi += 13;
        p_m++;
    }
}

void merge(short* array, int const left, int const mid, int const right,  int n)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
        Op += 2;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        Op + 3;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        Op += 3;
    }
    Os+= 3 + subArrayOne + subArrayTwo;
}

void printArray(short A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

