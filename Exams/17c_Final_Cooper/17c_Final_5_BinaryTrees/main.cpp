/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 9, 2022, 11:00 AM
 * Purpose: Final: Problem 5 Binary Trees
 */

#include <iostream>
#include <string>
#include <random>
#include <list>
#include <iomanip>
#include <map>
using namespace std;


struct Node
{
	string key;
	struct Node* left, * right;
};

// A utility function to create a new BST Node
struct Node* newNode(string item)
{
	struct Node* temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Stores inorder traversal of the BST
// in arr[]
void storeSorted(Node* root, string arr[], int& i)
{
	if (root != NULL)
	{
		storeSorted(root->left, arr, i);
		arr[i++] = root->key;
		storeSorted(root->right, arr, i);
	}
}

/* A utility function to insert a new
   Node with given key in BST */
Node* insert(Node* node, string key)
{

	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}


void treeSort(string arr[], int n)
{
	struct Node* root = NULL;

	// Construct the BST
	root = insert(root, arr[0]);
	for (int i = 1; i < n; i++)
		root = insert(root, arr[i]);

	int i = 0;
	storeSorted(root, arr, i);
}

// Given a 3 letter intial
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
	vector<string> temp;
	list<string> book[512];
	string rand_initials;
	// Generates 512 random initials
	// and number and pushes into
	// book
	for (int i = 0; i < 512; i++) {
		auto intial = random_intial();
		unsigned int index = intial_to_tele(intial) % 512;
		book[index].push_back(intial);
		temp.push_back(intial);
		if (i == 256) {
			rand_initials = intial;
		}
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

	treeSort(&temp[0], temp.size());
	cout << "Printing Tree" << endl;
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << " ";

	int tree_comp = -1;
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == rand_initials) {
			tree_comp = i;
			break;
		}
	int hash_comp = 0;
	cout << endl << rand_initials << endl;
	int check = intial_to_tele(rand_initials) % 512;
	hash_comp++;
	for (list<string>::iterator it = book[check].begin(); it != book[check].end(); ++it) {
		hash_comp++;
		if (*it == rand_initials) break;
	}
	cout << "Tree Comparisons: " << tree_comp;
	cout << "\nHash Comparisons: " << hash_comp;
}
