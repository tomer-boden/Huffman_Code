#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "BSTree.h"
#include "Priority_Queue.h"

using namespace std;

void buildBinarySearchTreeFromFile(BSTree*& binarySearchTree, ifstream& inFile); // build binary search tree from file
HuffmanTreeNode* buildHuffmanTree(BSTree*& binarySearchTree); //build Huffman Tree
bool isLeaf(HuffmanTreeNode* huffmanTreeNode); // check if huffman Tree Node is leaf
void printHuffmanCoding(HuffmanTreeNode* huffmanTree); // print Huffman Coding
void printHuffmanCodingRec(HuffmanTreeNode* huffmanTree, string str,int new_len, int* bit_size); // print Huffman Coding Rec
void printChCode(char ch, string str, int len); //print Char Code

