#pragma once
#include "Priority_Queue.h"

Priority_Queue::Priority_Queue(int maxSize) : _maxSize(maxSize) ,_heapSize(0)
{
	_data = new HuffmanTreeNode*[maxSize];
}

Priority_Queue::Priority_Queue(HuffmanTreeNode** HTNodeArr, int size) : _maxSize(size), _heapSize(size)
{
	_data = HTNodeArr;

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

Priority_Queue::~Priority_Queue()
{
	if (_data) {
		for (int i = 0; i < _heapSize; i++)
			delete _data[i];
	}
	delete _data;
}

int Priority_Queue::parent(int node)
{
	return (node - 1) / 2;
}

int Priority_Queue::left(int node)
{
	return (2 * node + 1);
}

int Priority_Queue::right(int node)
{
	return (2 * node + 2);
}


void Priority_Queue::FixHeap(int node)
{
	int min;
	int _left = left(node);
	int _right = right(node);
	if ((_left < _heapSize) && (_data[_left]->get_frequancy() < _data[node]->get_frequancy()))
		min = _left;
	else min = node;
	if ((_right < _heapSize) && (_data[_right]->get_frequancy() < _data[min]->get_frequancy()))
		min = _right;

	if (min != node)
	{
		char char_temp = _data[node]->get_ch();
		int int_temp = _data[node]->get_frequancy();
		HuffmanTreeNode* temp_left = _data[node]->get_Left();
		HuffmanTreeNode* temp_right = _data[node]->get_right();
		_data[node]->SetFrequancy(_data[min]->get_frequancy());
		_data[node]->SetCh(_data[min]->get_ch());
		_data[node]->SetLeft(_data[min]->get_Left());
		_data[node]->SetRight(_data[min]->get_right());
		_data[min]->SetLeft(temp_left);
		_data[min]->SetRight(temp_right);
		_data[min]->SetFrequancy(int_temp);
		_data[min]->SetCh(char_temp);
		FixHeap(min);
	}
}

void Priority_Queue::MakeEmpty() {
	if (_data) {
		for (int i = 0; i < _heapSize; i++)
			delete _data[i];
	}
	_data = nullptr;
}

bool Priority_Queue::isEmpty() {
	if (!_heapSize)
		return true;
	else
		return false;
}

HuffmanTreeNode* Priority_Queue::DeleteMin()
{
	if (_heapSize < 1)
		return nullptr;
	HuffmanTreeNode* min = new HuffmanTreeNode(*_data[0]);
	_heapSize--;
	_data[0] = _data[_heapSize];
	FixHeap(0);
	return (min);
}

void Priority_Queue::insertMin(HuffmanTreeNode* Item)
{
	if (_heapSize == _maxSize)
	{
		cout << "Heap is full" << endl;
	}
	int i = _heapSize;
	while ((i > 0) && (_data[parent(i)]->get_frequancy() > Item->get_frequancy()))
	{
		_data[i] = _data[parent(i)];
		i = parent(i);
	}
	_data[i] = Item;
	_heapSize++;
}
