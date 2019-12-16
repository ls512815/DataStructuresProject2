/*
Name: Lydia Shiffler 
Date: 3/5/17
Description: added insert, extract_min, peek, and size functions 
*/


#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  MinHeap() {}
  ~MinHeap() {}

  void insert(const T data, const int key);
  T extract_min();

  T peek() const;


  int size() const 
  {
    return heap.size();
  };      

private:
  vector<HeapNode<T> > heap;
};


template <typename T>
void MinHeap<T>::insert(const T data, const int key) 
{  
  heap.push_back(*new HeapNode<T>(data,key));
  int i = heap.size() - 1;
  while(i > 0 && (heap[i] < heap[ceil(i / 2.0) - 1]))
  {
    HeapNode<T> temp = heap[i];
    heap[i] = heap[ceil(i / 2.0) - 1];
    heap[ceil(i / 2.0) - 1] = temp;
    i = ceil(i / 2.0) - 1;
  }

}


template <typename T>
T MinHeap<T>::extract_min() 
{                        
  T returnvalue = heap[0].data;
  int i = 0;
  heap[0] = heap[heap.size() - 1];
  heap.pop_back();
  while(i * 2 + 2 <= heap.size() && ((heap[(i * 2) + 1] < heap[i]) || (i * 2 + 2 < heap.size() && heap[(i * 2) + 2] < heap[i])))
  {
    if(i * 2 + 2 < heap.size() && (heap[(i + 2) + 2] <= heap[(i * 2) + 1]))
    {
      HeapNode<T> temp = heap[i];
      heap[i] = heap[(i * 2) + 2];
      heap[(i * 2) + 2] = temp;
      i = (i * 2) + 2;

    }
    else 
    {
      HeapNode <T> temp = heap[i];
      heap[i] = heap[(i * 2) + 1];
      heap[(i * 2) + 1] = temp;
      i = (i * 2) + 1;
    }
  }
  return returnvalue;
}

template <typename T>
inline T MinHeap<T>::peek() const
{
  return heap[0].data;
}

