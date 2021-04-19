//build a search tree containing the given array
//build an hofman code

#include "main.h"


int main(void)
{
	char filename[128];
	ifstream inFile;
	BSTree* binarySearchTree = nullptr;
	cout << "please enter file name: " << endl;
	cin >> filename;
	inFile.open(filename);
	if (!inFile)
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	buildBinarySearchTreeFromFile(binarySearchTree, inFile);
	HuffmanTreeNode* huffmanTreeNode = buildHuffmanTree(binarySearchTree);
	printHuffmanCoding(huffmanTreeNode);
	delete binarySearchTree;
	delete huffmanTreeNode;
}

void buildBinarySearchTreeFromFile(BSTree*& binarySearchTree, ifstream& inFile) {
	Pair p;

	binarySearchTree = new BSTree();
	p.frequency = 1;
	inFile.get(p.letter);

	while (!inFile.eof())
	{
		binarySearchTree->Insert(p);
		inFile.get(p.letter);
	}
}

HuffmanTreeNode* buildHuffmanTree(BSTree*& binarySearchTree) {
	int size = binarySearchTree->getSize();
	
	HuffmanTreeNode** A = new HuffmanTreeNode*[size];
	for (int i = 0; i < size; i++)
		A[i] = new HuffmanTreeNode();
	binarySearchTree->InsertToHuffmanTreeNodeArray(A, const_cast<BSTreeNode*>(binarySearchTree->getRoot()), 0);
	
	Priority_Queue* heap = new Priority_Queue(A, size);
	for (int i = 1; i < size; i++)
		{
			HuffmanTreeNode* huffmanTreeNode = new HuffmanTreeNode();
			huffmanTreeNode->SetLeft((heap->DeleteMin()));
			huffmanTreeNode->SetRight((heap->DeleteMin()));
			huffmanTreeNode->SetFrequancy(huffmanTreeNode->get_Left()->get_frequancy() + huffmanTreeNode->get_right()->get_frequancy());
			heap->insertMin(huffmanTreeNode);
		}
	HuffmanTreeNode* res = heap->DeleteMin();
	delete heap;
	return res;
}

void printHuffmanCoding(HuffmanTreeNode* huffmanTree)
{
	int length = 0;
	int i = 0;
	int* bit_size = &i;
	if (isLeaf(huffmanTree))
	{
		*bit_size = *bit_size + (huffmanTree->get_frequancy());
		printChCode(huffmanTree->get_ch(), "1", 1);
		cout << "Encoded file weight:" << *bit_size << " bits" << endl;
		return;
	}
	printHuffmanCodingRec(huffmanTree, "", length, bit_size);
	cout << "Encoded file weight:" << *bit_size << " bits" <<endl;
}

void printHuffmanCodingRec(HuffmanTreeNode* huffmanTree, string str, int length, int* bit_size) {
	if (isLeaf(huffmanTree))
	{
		*bit_size = *bit_size + (huffmanTree->get_frequancy() * length);
		printChCode(huffmanTree->get_ch(), str, length);
		return;
	}
	printHuffmanCodingRec(huffmanTree->get_Left(), str + "0", length + 1, bit_size);
	printHuffmanCodingRec(huffmanTree->get_right(), str + "1", length + 1, bit_size);
}

void printChCode(char ch, string str, int len) {
	if (ch == '\n')
		cout << "'\\n'" << '-' << str << endl;
	else
		cout << "'" << ch << "'" << '-' << str << endl;
	 
}

bool isLeaf(HuffmanTreeNode* huffmanTreeNode) {
	return !(huffmanTreeNode->get_Left()) && !(huffmanTreeNode->get_right());
}