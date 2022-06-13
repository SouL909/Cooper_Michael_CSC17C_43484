/* 
 * File:   DoubleLink.h
 * Author: Michael Cooper
 * Purpose: DoubleLink Header File
 * Created on 6/5/22
 */

#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H

#include "Link.h"

#include <iostream>

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
    head->lnkPrev = nullptr;
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
    Link<T>* prev = tail->lnkPrev;
    delete tail;
    tail = prev;
  }
  void push_back(T data) {
    if(head == nullptr) {
      head = new Link<T>();
      head->data = data;
      head->lnkNext = nullptr;
      tail = head;
      tail->lnkPrev = nullptr;
    } else {
      tail->lnkNext = new Link<T>();
      Link<T>* temp = tail;
      tail = tail->lnkNext;
      tail->data = data;
      tail->lnkNext = nullptr;
      tail->lnkPrev = temp;
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
    head->lnkPrev = nullptr;
  }
  void push_front(T data) {
    if(head == nullptr) {
      head = new Link<T>();
      head->data = data;
      head->lnkNext = nullptr;
      head->lnkPrev = nullptr;
      tail = head;
    } else {
      Link<T>* temp = new Link<T>();
      temp->data = data;
      temp->lnkNext = head;
      temp->lnkPrev = nullptr;
      head->lnkPrev = temp;
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

#endif /* DOUBLE_LINK_H */


