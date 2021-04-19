#include "BSTreeNode.h" 

using namespace std;

BSTreeNode::BSTreeNode() : _left(nullptr), _right(nullptr), _value(nullptr)
{
}


BSTreeNode::BSTreeNode(const Pair& value, const BSTreeNode* _left,  const BSTreeNode* _right) : _left(const_cast<BSTreeNode*>(_left)), _right(const_cast<BSTreeNode*>(_right))
{
	_value = new Pair();
	_value->letter = value.letter;
	_value->frequency = value.frequency;
}

BSTreeNode::~BSTreeNode() {
	if (_left)
	delete _left;
	if(_right)
	delete _right;
}

bool BSTreeNode::setRight(BSTreeNode* _right) {
	this->_right = _right;
	return true;
}

bool BSTreeNode::setLeft(BSTreeNode* _left) {
	this->_left = _left;
	return true;
}

bool BSTreeNode::setValue(const Pair& value) {
	_value->letter = value.letter;
	_value->frequency = value.frequency;
	return true;
}

bool BSTreeNode::setValueLetter(const char ch) {
	_value->letter = ch; 
	return true;
}

bool BSTreeNode::setValueFrequency(const int frequency) {
	_value->frequency = frequency;
	return true;
}

void BSTreeNode::PrintInorder()
{
	if (_left)
	{
		_left->PrintInorder();
	}
	if(_value->letter == '\n')
		cout << "'\\n'" << "," << _value->frequency << endl;
	else
		cout << _value->letter << "," << _value->frequency << endl;
	if (_right)
		_right->PrintInorder();
}

