/* 
 * File:   Tree.h
 * Author: Michael Cooper
 * Purpose: Tree Header File
 * Created on 6/8/22
 */

#ifndef TREE_H
#define TREE_H
#include <iostream>

template<class T>
struct Leaf {
	T data;
	Leaf<T>* left = nullptr;
	Leaf<T>* right = nullptr;	
};

template<class T>
void insert(Leaf<T>*& root, T data) {
	if (root == nullptr) {
		root = new Leaf<T>;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (data < root->data)
			insert(root->left, data);
		else
			insert(root->right, data);
	}
}

template<class T>
class Tree {
	Leaf<T>* stem;
public:
	Tree() {
		stem = nullptr;
	}
	void push(T data) {
		if (stem == nullptr) {
			stem = new Leaf<T>;
			stem->data = data;
			stem->left = nullptr;
			stem->right = nullptr;
		} else {
			insert(stem, data);
		}
	}

	void printPostorder() {
		if (stem == nullptr)
			return;
		// first recur on left subtree
		printPostorder(stem->left);

		// then recur on right subtree
		printPostorder(stem->right);

		// now deal with the node
		std::cout << stem->data << " ";
	}

	void printPostorder(Leaf<T>* node)
	{
		if (node == nullptr)
			return;

		// first recur on left subtree
		printPostorder(node->left);

		// then recur on right subtree
		printPostorder(node->right);

		// now deal with the node
		std::cout << node->data << " ";
	}

};

#endif // TREE_H

