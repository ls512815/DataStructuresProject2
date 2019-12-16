/*
Name: Lydia Shiffler 
Date: 3/5/17
Description: main 
*/
//time complexity with a min heap is Nlog(N)
//time complexity without a min heap is log(N)

#include <iostream>
#include "huffman_tree.h"
#include "min_heap.h"
using namespace std;

int main(int argc, char** argv) 
{
  HuffmanTree tree;
  string input;
  for(int i = 1; i < 4; i++)
  {
  	cout << "Enter a word:" << endl; 
  	cin >> input; 
  	tree.construct(input);
  	cout << "Test case:" << i << endl;
  	tree.print();
  	tree.destruct();
  	cout << endl;
  }
}
