/*
* File:   SimpleVector.h
 * Author: rcc
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include "Link.h"
using namespace std;

template <class T>
class SimpleVector
{
private:
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   LinkedList<T> ll;

public:
   // Default constructor
   SimpleVector()
      { arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   Link<T>* getElementAt(int position);

   // Overloaded [] operator declaration
   Link<T>* &operator[](int);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      ll.push_back(0);
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      ll.push_back(obj.getElementAt(count)->data);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   ll.dstryLst();
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
Link<T>* SimpleVector<T>::getElementAt(int sub)
{
  if(sub >= arraySize) {
    for(int i = 0; i < arraySize;i++)
      ll.push_back(0);
    arraySize*=2;
  }
   if (sub < 0 || sub >= arraySize)
      subError();
  Link<T>* temp = ll.head;
   for(int i = 0; i < sub;i++){
     temp = temp->lnkNext;
   } 
  return temp;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
Link<T>* &SimpleVector<T>::operator[](int sub)
{
  if(sub >= arraySize) {
    for(int i = 0; i < arraySize;i++)
      ll.push_back(0);
    arraySize*=2;
  }
   if (sub < 0 || sub >= arraySize)
      subError();
   Link<T>* temp = ll.head;
   for(int i = 0; i < sub;i++){
     temp = temp->lnkNext;
   } 
  return temp;
}
#endif