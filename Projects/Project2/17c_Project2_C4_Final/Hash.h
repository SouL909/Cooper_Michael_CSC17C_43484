/* 
 * File:   Hash.h
 * Author: Michael Cooper
 * Purpose: Hash Header File
 * Created on 6/8/22
 */

#ifndef HASH_H
#define HASH_H

#include "DoubleLink.h"
#include <string>
#include <iostream>

class Hash {
public:
  static const int SIZE  = 10;
  struct Node {
    std::string key;
    int value;
  };
  LinkedList<Node>* table;
  unsigned int ELFHash(const std::string& key) {
    unsigned int hash = 0;
    unsigned int x    = 0;
    
    for(std::size_t i = 0; i < key.length(); i++)
    {
      hash = (hash << 4) + key[i];
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
    }
    
    return hash;
  }
public:
  Hash() {
    table = new LinkedList<Node>[SIZE];
    for(int i = 0; i < SIZE; i++) {
      table[i] = LinkedList<Node>();
    }
  }
  void push(std::string key, int value) {
    int index = (ELFHash(key) % SIZE);
    Node node;
    node.key = key;
    node.value = value;
    table[index].push_back(node);
  }

  bool find(std::string key) {
    int index = (ELFHash(key) % SIZE);
    Link<Node>* prev = table[index].head;
      while(prev != nullptr) {
        if(prev->data.key == key)
            return true;
        prev = prev->lnkNext;
      }
    return false;
  }
  
  void print_table() {
    for(int i = 0; i < SIZE; i++) {
      Link<Node>* prev = table[i].head;
      while(prev != nullptr) {
        std::cout << "Key: " << prev->data.key << "\tValue: " << prev->data.value << std::endl;
        prev = prev->lnkNext;
      }
    }
  }
};

#endif // HASH_H
