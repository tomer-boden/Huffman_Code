#pragma once
#include <iostream>
#include "pair.h"

using namespace PairItem;

class BSTreeNode {
	private:
		Pair* _value;
		BSTreeNode* _left, * _right;
	public:
		//constructors
		BSTreeNode();
		BSTreeNode(const Pair& item, const BSTreeNode* _left, const BSTreeNode* _right);
		//distructor
		~BSTreeNode();
		//getters
		const Pair& getValue() { return *this->_value; }
		const BSTreeNode* getLeft() { return  this->_left; }
		const BSTreeNode* getRight() { return  this->_right; }
		//setters
		bool setRight(BSTreeNode* _right);
		bool setLeft(BSTreeNode* _left);
		bool setValue(const Pair& value);
		bool setValueLetter(const char ch);
		bool setValueFrequency(const int frequency);
		void PrintInorder();
};