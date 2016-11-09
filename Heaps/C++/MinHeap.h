#ifndef _MIN_HEAP
#define _MIN_HEAP
#include <vector>
using namespace std;

class MinHeap {
public:
  /*
  *   MinHeap: constructor
  *   Action: creates heap from null.
  */
  MinHeap();

  /*
  *   MinHeap: constructor
  *   Action: builds heap from existing array - not sorted.
  */
  MinHeap(const vector<int> &arr);

  /*
  *   buildHeap:
  *   Action: Given a vector array of integers, sorts them into a proper heap
  */
  void buildHeap(const vector<int> &arr);

  /*
  *   minHeapify:
  *   Action: given a new integer i, insert the integer into the correct place
  *     in the heap, and make sure the heap is correctly sorted
  */
  void insert(int i);

  /*
  *   peekMin:
  *   Action: returns the value of the smallest number in the heap without
  *     removing it
  */
  int peekMin();

  /*
  *   getMin:
  *   Action: removes and returns the smallest object in the heap, resorting
  *     the rest of the heap as appropriate (bubble up)
  */
  int getMin();

  /*
  *   getSize:
  *   Action: returns the number of elements in the heap
  */
  int getSize() const;

  /*
  *   operator=:
  *   Action: compares two heaps
  */
  bool operator==(const MinHeap &heap) const;

  /*
  *   getElem():
  *   Action: returns the value of the given element
  */
  int getElem(int v) const;

  void printHeap();

private:
  vector<int> heap;     // the heap itself

  /*
  *   swap:
  *   Action: given the location of two values within the heap, the items are
  *     swapped.
  */
  void swap(int x, int y);

  /*
  *   getLeft:
  *   Action: given a vector in the heap, the location of the left child is
  *     returned
  */
  int getLeft(int v);

  /*
  *   getRight:
  *   Action: given a vector in the heap, the location of the right child is
  *     returned
  */
  int getRight(int v);

  /*
  *   getParent:
  *   Action: given a vector in the heap, the location of the parent is
  *     returned.
  */
  int getParent(int v);

  void bubbleUp(int v, int k);

  void bubbleDown(int v);
};

#endif
