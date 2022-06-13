/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on May 24, 2022, 5:00 PM
 * Purpose: Hashing Assignment - Hash Table
 */

#include <iostream>
#include <string>
#include "DoubleLink.h"
#include <chrono>
using namespace std;
class Hash {
  static const int SIZE  = 10;
  struct Node {
    string key;
    int value;
  };
  LinkedList<Node>* table;
  unsigned int ELFHash(const string& key) {
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
  void push(string key, int value) {
    int index = (ELFHash(key) % SIZE);
    Node node;
    node.key = key;
    node.value = value;
    table[index].push_back(node);
  }

  bool find(string key) {
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
        cout << "Key: " << prev->data.key << "\tValue: " << prev->data.value << endl;
        prev = prev->lnkNext;
      }
    }
  }
};

int main() {
  Hash table;
  table.push("one", 1);

  table.push("two", 2);

  table.push("three", 3);

  table.push("four", 4);

  table.push("five", 5);

  table.push("six", 6);

  table.push("seven", 7);

  table.push("eight", 8);

  table.push("nine", 9);

  table.push("ten", 10);

  table.print_table();


  auto begin = std::chrono::steady_clock::now();
  bool found = table.find("ten");
  auto end = std::chrono::steady_clock::now();
  cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds." <<endl;
  
  if(found) {
    cout << "found ten" << endl;
  }

  begin = std::chrono::steady_clock::now();
  found = table.find("eleven");
  end = std::chrono::steady_clock::now();
  cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanoseconds." <<endl;
  
  if(!found) {
    cout << "Did not find eleven" << endl;
  }
}