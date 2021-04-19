#pragma once

class HuffmanTreeNode
{
	private:
		char _ch;
		float _frequency;
		HuffmanTreeNode *_left, *_right;
	public:
		//constructors
		HuffmanTreeNode();
		HuffmanTreeNode(char ch, float frequency);
		HuffmanTreeNode(const HuffmanTreeNode& otherHuffmanTreeNode);
		//distructor
		~HuffmanTreeNode();
		//getters
		HuffmanTreeNode* get_Left() { return this->_left; }
		HuffmanTreeNode* get_right() { return this->_right; }
		const float get_frequancy() { return this->_frequency; }
		const char get_ch() { return this->_ch; }
		//setters
		bool SetLeft(HuffmanTreeNode* Node);
		bool SetRight(HuffmanTreeNode* Node);
		bool SetFrequancy(float frequency);
		bool SetCh(char ch);

};
