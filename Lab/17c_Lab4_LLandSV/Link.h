/*
    Author: Michael Cooper
    Date:   4/27/22
    Purpose:Linked from first principles
 */

#ifndef LINK_H
#define LINK_H
#include <iostream>

template<class T>
struct Link{
    T data;     //Some type of data
    Link<T> *lnkNext; //Next Link in the chain
};
template<class T>
class LinkedList {
public:
  Link<T>* head;
  Link<T>* tail;
public:
  LinkedList<T>() {
    head = nullptr;
    tail = head;
  }
  LinkedList<T>(T data) {
    head = new Link<T>();
    head->data = data;
    head->lnkNext = nullptr;
    tail = head;
  }
  void pop_back() {
    if(head == nullptr) {
      return;
    }
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = head;
      return;
    }
    Link<T>* prev = head;
    while(prev->lnkNext != nullptr) {
      if(prev->lnkNext == tail) {
        delete tail;
        tail = prev->lnkNext;
      }
      prev = prev->lnkNext;
    }
  }
  void push_back(T data) {
    if(head == nullptr) {
      head = new Link<T>();
      head->data = data;
      head->lnkNext = nullptr;
      tail = head;
    } else {
      tail->lnkNext =  new Link<T>();
      tail = tail->lnkNext;
      tail->data = data;
      tail->lnkNext = nullptr;
    }
  }
  void pop_front() {
    if (head == nullptr) {
      return;
    }
    Link<T>* temp = head->lnkNext;
    if (head == tail) {
      tail = temp;
    }
    delete head;
    head = temp;
  }
  void push_front(T data) {
    if(head == nullptr) {
      head = new Link<T>();
      head->data = data;
      head->lnkNext = nullptr;
      tail = head;
    } else {
      Link<T>* temp = new Link<T>();
      temp->data = data;
      temp->lnkNext = head;
      head = temp;
    }
  }
  void prntLst() {
    Link<T>* prev = head;
    while(prev != nullptr) {
      std::cout << prev->data << " ";
      prev = prev->lnkNext;
    }
  }
  void dstryLst() {
    Link<T>* next = head;
    while(next != nullptr)
    {
      Link<T>* temp = next->lnkNext;
      delete next;
      next = temp;
    }
    head = nullptr;
    tail = nullptr;
  }
};

#endif /* LINK_H */