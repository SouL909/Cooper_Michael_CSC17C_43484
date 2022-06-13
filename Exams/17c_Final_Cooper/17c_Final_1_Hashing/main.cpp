/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 5, 2022, 8:53 PM
 * Purpose: Final: Problem 1 Hashing
 */

#include <iostream>
#include <string>
#include <random>
#include <list>
#include <iomanip>
#include <map>
using namespace std;

// Given a 3 letter initial
// Output some number
// that correlates to the numbers
// of a telephone number
unsigned int tele_letter(char chr) {
	if (chr >= 'a' && chr <= 'c' || chr >= 'A' && chr <= 'C') {
		return 2;
	}
	else if (chr >= 'd' && chr <= 'f' || chr >= 'D' && chr <= 'F') {
		return 3;
	}
	else if (chr >= 'g' && chr <= 'i' || chr >= 'G' && chr <= 'I') {
		return 4;
	}
	else if (chr >= 'j' && chr <= 'l' || chr >= 'J' && chr <= 'L') {
		return 5;
	}
	else if (chr >= 'm' && chr <= 'o' || chr >= 'M' && chr <= 'O') {
		return 6;
	}
	else if (chr >= 'p' && chr <= 's' || chr >= 'P' && chr <= 'S') {
		return 7;
	}
	else if (chr >= 't' && chr <= 'v' || chr >= 'T' && chr <= 'V') {
		return 8;
	}
	else if (chr >= 'w' && chr <= 'z' || chr >= 'W' && chr <= 'Z') {
		return 9;
	}
	else if (chr == '+') {
		return 0;
	}
	else {
		return 1;
	}
}
// Converts 3 letter intials
// to a number
// Ex: MEL -> 635
unsigned int intial_to_tele(string inital) {
	return tele_letter(inital[0]) * 100
		+ tele_letter(inital[1]) * 10
		+ tele_letter(inital[2]);
}
// Return a string that consists of
// three intials
string random_intial() {
	random_device dev;
	mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(65, 87); // 'A' -> 65, 'Z' -> 87
	string intials;
	intials.push_back(static_cast<char>(dist(rng)));
	intials.push_back(static_cast<char>(dist(rng)));
	intials.push_back(static_cast<char>(dist(rng)));

	return intials;
}

int main(int argc, char** argv) {
	list<string> book[512];
	// Generates 512 random initials
	// and number and pushes into
	// book
	for (int i = 0; i < 512; i++) {
		auto intial = random_intial();
		unsigned int index = intial_to_tele(intial) % 512;
		book[index].push_back(intial);
	}
	int elements = 0;
	int max = 0;
	map<int, int> freq;
	// Loops over the book array
	// and checks for amount of elements in
	// each element of book and max collisions
	for (int i = 0; i < 512; i++) {
		cout << "[" << i + 1 << "] ";
		for (int j = 0; j < book[i].size(); j++)
			cout << "*";
		if (freq.find(book[i].size()) != freq.cend()) {
			freq[book[i].size()]++;
		}
		else {
			freq.insert(make_pair(book[i].size(), 1));
		}
		if (max < book[i].size())
			max = book[i].size();
		elements += book[i].size();
		cout << endl;
	}
	// Display info
	cout << "There are a total of " << elements << " elements." << endl;
	for (auto var : freq) {
		cout << "There are " << var.second << " lists with " << var.first << " elements." << endl;
	}
	cout << "Maximum amount of collisions " << max << "." << endl;
}
