#include "BSTree.h" 

BSTree::BSTree() : _root(nullptr), _size(0)
{
}

BSTree::~BSTree()
{
	delete _root;
}

BSTreeNode* BSTree::Find(char key)
{
	BSTreeNode* temp = _root;
	while (temp)
	{
		if (key == (temp->getValue().letter))
			return temp;
		else if (key < (temp->getValue().letter))
			temp = const_cast<BSTreeNode*>(temp->getLeft());
		else
			temp = const_cast<BSTreeNode*>(temp->getRight());
	}
	return nullptr;
}

void BSTree::Insert(const Pair& value)
{
	BSTreeNode* bsTreeNodeExists = Find(value.letter);
	if (bsTreeNodeExists)
	{
		bsTreeNodeExists->setValueFrequency(bsTreeNodeExists->getValue().frequency +1);
		return;
	}
	BSTreeNode* temp = _root;
	BSTreeNode* parent = nullptr;
	BSTreeNode* newnode;

	while (temp)
	{
		parent = temp;
		if (value.letter < parent->getValue().letter)
			temp = const_cast<BSTreeNode*>(temp->getLeft());
		else temp = const_cast<BSTreeNode*>(temp->getRight());
	}
	newnode = new BSTreeNode(value, nullptr, nullptr);
	if (!parent)
		_root = newnode;
	else if (value.letter < parent->getValue().letter)
		parent->setLeft(newnode);
	else parent->setRight(newnode);
	_size++;
}		

void BSTree::Delete(char key)
{
	BSTreeNode* temp = _root;
	BSTreeNode* parent = nullptr;
	bool isRight = true;

	if (Find(key))
		_size--;
	while (temp) {
		parent = temp;
		if (key < parent->getValue().letter) {
			temp = const_cast<BSTreeNode*>(temp->getLeft());
			isRight = false;
		}
		else { 
			temp = const_cast<BSTreeNode*>(temp->getRight());
		}
	}
	if (!(temp->getRight()) || !(temp->getLeft())) 
	{
		if (temp->getRight()) {
			if (isRight)
				parent->setRight(const_cast<BSTreeNode*>(temp->getRight()));
			else
				parent->setLeft(const_cast<BSTreeNode*>(temp->getRight()));
		}
		else 
		{
			if (isRight)
				parent->setRight(const_cast<BSTreeNode*>(temp->getLeft()));
			else
				parent->setLeft(const_cast<BSTreeNode*>(temp->getLeft()));
		}
		delete temp;
	}

	BSTreeNode* toDelete = max(temp->getLeft());
	Pair toDeleteValue = toDelete->getValue();
	Delete(toDelete->getValue().letter);
	temp->setValue(toDelete->getValue());
}

BSTreeNode* BSTree::max(const BSTreeNode* root) {
	BSTreeNode* current = const_cast<BSTreeNode*>(root);
	while (current->getRight() != nullptr)
		current = const_cast<BSTreeNode*>(current->getRight());
	return current;
}

int BSTree::InsertToHuffmanTreeNodeArray(HuffmanTreeNode** A, BSTreeNode* Node, int i) {
	if (Node == nullptr)
		return i;

	A[i]->SetFrequancy(Node->getValue().frequency);
	A[i]->SetCh(Node->getValue().letter);
	i++;
	if (Node->getLeft() != nullptr)
		i = InsertToHuffmanTreeNodeArray(A, const_cast<BSTreeNode*>(Node->getLeft()), i);
	if (Node->getRight() != nullptr)
		i = InsertToHuffmanTreeNodeArray(A, const_cast<BSTreeNode*>(Node->getRight()), i);
	return i;
}