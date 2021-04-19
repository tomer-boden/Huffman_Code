#pragma once
#include "BSTreeNode.h"
#include "Node_hoffman.h"

using namespace std;

class BSTree {
	private :
		BSTreeNode* _root;
		int _size;
	public:
		//constructor
		BSTree();
		//distructor
		~BSTree();
		//getters
		const BSTreeNode* getRoot() { return this->_root; }
		const int getSize() { return this->_size; }
		//setters
		bool setRoot(BSTreeNode* newRoot) { this->_root = newRoot; }
		bool setSize(const int size) { this->_size = size; }

		BSTreeNode* Find(char key);
		void Insert(const Pair& item);
		void Delete(char key);
		BSTreeNode* max(const BSTreeNode* root);
		int InsertToHuffmanTreeNodeArray(HuffmanTreeNode** A, BSTreeNode* root, int i);
};