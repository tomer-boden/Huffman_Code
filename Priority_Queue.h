#pragma once
#include <iostream>
#include "Node_hoffman.h"

using namespace std;

class Priority_Queue {
	private:
		HuffmanTreeNode** _data = nullptr;
		int _maxSize;
		int _heapSize;
		static int left(int node);
		static int right(int node);
		static int parent(int node);
		void FixHeap(int node);
	public:
		//constructors
		Priority_Queue(int maxSize);
		Priority_Queue(HuffmanTreeNode** HTNodeArr, int size);
		//distructor
		~Priority_Queue();
		//getters
		HuffmanTreeNode** getData() {return this->_data;}
		HuffmanTreeNode* min() { return _data[0]; }

		void MakeEmpty();
		bool isEmpty();
		HuffmanTreeNode* DeleteMin();
		void insertMin(HuffmanTreeNode* item);
};