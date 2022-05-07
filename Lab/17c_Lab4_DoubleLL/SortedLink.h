#ifndef SORT_LINK_H
#define SORT_LINK_H

#include "Link.h"
#include <iostream>

template<class T>
class SortedLinkedList {
public:
  Link<T>* head;
  Link<T>* tail;
  SortedLinkedList<T>() {
    head = nullptr;
    tail = head;
  }
  SortedLinkedList<T>(T data) {
    head = new Link<T>();
    head->data = data;
    head->lnkNext = nullptr;
    head->lnkPrev = nullptr;
    tail = head;
  }

  void push(T data) {
    if(head == nullptr) {
      head = new Link<T>();
      head->data = data;
      head->lnkNext = nullptr;
      tail = head;
    } else {
        if(head->lnkNext == nullptr) {
          Link<T>* temp = new Link<T>;
          temp->data = data;
          temp->lnkNext = nullptr;
          temp->lnkPrev = nullptr;
          if(data < head->data) {
            head->lnkPrev = temp;
            temp->lnkNext = head;
            head = temp;
          } else {
            head->lnkNext = temp;
            temp->lnkPrev = head;
          }
          return;
        }
        Link<T>* prev = head;
        while(prev != nullptr) {
          if(data < prev->data) {
            Link<T>* temp = new Link<T>;
            temp->data = data;
            if(head == prev) {
              temp->lnkPrev = nullptr;
              temp->lnkNext = head;
              head->lnkPrev = temp;
              head = temp;
              return;
            }
            if(prev->lnkPrev != nullptr)
              prev->lnkPrev->lnkNext = temp;
            temp->lnkNext = prev;
            prev->lnkPrev = temp;
            return;
          }
          prev = prev->lnkNext;
        }
      }
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

  void prntLst() {
    Link<T>* prev = head;
    while(prev != nullptr) {
      std::cout << prev->data << ",";
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

#endif