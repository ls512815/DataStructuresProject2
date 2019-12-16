/*
Name: Lydia Shiffler 
Date: 3/5/17
Description: added print and help function 
*/


#include <iostream>
#include "huffman_tree.h"
#include "min_heap.h"
using namespace std;

void HuffmanTree::construct(const string message) {
  this->message = message;

  // Count the frequency of each letter in message
  // e.g. 
  //    message == "aaabbccccdd"
  //    frequencies == {a:3, b:2, c:4, d:2} 
  map<char, int> frequency_map;
  for (int i = 0; i < message.length(); ++i) {
    if (frequency_map.find(message[i]) != frequency_map.end())
      ++frequency_map[message[i]];
    else
      frequency_map[message[i]] = 1;
  }

  // Create HuffmanNode for each unique letter in message
  // and organize nodes into a min heap
  // e.g.
  //  heap == 
  //            {b:2}  
  //           /     \
  //        {d:2}   {a:3}
  //        /   \   /    \
  //      {c:4} 
  MinHeap<HuffmanNode*> heap;
  map<char, int>::iterator it = frequency_map.begin();
  for (; it != frequency_map.end(); ++it) {
    HuffmanNode* node = new HuffmanNode(
      it->first, it->second
    );
    heap.insert(node, it->second);
  }

  // Combine nodes with smallest frequency and insert
  // back into heap until heap size == 1. Along the way,
  // create binary tree out of combined nodes.
  // e.g.;
  //  (1)
  //     {b:2} == heap.extract_min()
  //     {d:2} == heap.extract_min()
  //     parent ==
  //               {*:4}
  //              /     \
  //            {b:2}  {d:2}
  //
  //     heap == 
  //              {a:3}
  //             /     \
  //           {c:4}   {*:4}
  //
  //  (2)
  //     {a:3} == heap.extract_min()
  //     {c:4} == heap.extract_min()
  //     parent ==
  //              {*:7}
  //             /     \
  //          {a:3}   {*:4}
  //    
  //     heap ==
  //            {c:4}
  //           /
  //         {*:7}
  //
  //  (3)
  //     {*:4} == heap.extract_min()
  //     {*:7} == heap.extract_min()
  //     parent ==
  //            {*:11}
  //           /       \
  //      {c:4}        {*:7}
  //                  /     \
  //                {a:3}  {*:4}
  //                       /    \
  //                    {b:2}  {d:2}
  //
  //     heap == {*:11}
  while (heap.size() > 1) {
    HuffmanNode *left, *right;

    left = heap.extract_min();
    right = heap.extract_min();

    HuffmanNode *parent = new HuffmanNode(
      left->frequency + right->frequency
    );

    parent->left = left;
    parent->right = right;

    heap.insert(parent, parent->frequency);
  }

  // Get root of huffman tree. e.g. {*:11}
  this->root = heap.peek();
}


void HuffmanTree::print() const 
{   
  map <char, string> code_map;
  string x;
  help(root, x, code_map);

  for(int i = 0; i < message.length(); i++)
  {
    cout << code_map[message[i]] << " ";
  }

}

void HuffmanTree::help(HuffmanNode* helproot, string str, map<char, string> & map) const
{
  if(helproot == NULL)
  {
    return;
  }

  if(helproot -> left == NULL && helproot -> right == NULL)
  {
    map[helproot -> character] = str; 
  }

  help(helproot -> left, str + "0", map);
  help(helproot -> right, str + "1", map);
}

