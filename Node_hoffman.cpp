#pragma once
#include "Node_hoffman.h"


HuffmanTreeNode::HuffmanTreeNode() : _ch('0'), _frequency(0), _left(nullptr), _right(nullptr)
{
}

HuffmanTreeNode::HuffmanTreeNode(char ch, float frequency) : _ch(ch), _frequency(frequency), _left(nullptr), _right(nullptr)
{
}

HuffmanTreeNode::HuffmanTreeNode(const HuffmanTreeNode& otherHuffmanTreeNode) {
	this->_ch = otherHuffmanTreeNode._ch;
	this->_frequency = otherHuffmanTreeNode._frequency;
	this->_left = otherHuffmanTreeNode._left;
	this->_right = otherHuffmanTreeNode._right;
}

HuffmanTreeNode::~HuffmanTreeNode()
{
	if (_left)
		delete _left;
	if (_right)
		delete _right;
}

bool HuffmanTreeNode::SetLeft(HuffmanTreeNode* Node) { 
	this->_left = Node; 
	return true;
}

bool HuffmanTreeNode::SetRight(HuffmanTreeNode* Node) { 
	this->_right = Node;
	return true;
}

bool HuffmanTreeNode::SetFrequancy(float frequency) {
	this->_frequency = frequency;
	return true;
}

bool HuffmanTreeNode::SetCh(char ch) { 
	this->_ch = ch;
	return true;
}
