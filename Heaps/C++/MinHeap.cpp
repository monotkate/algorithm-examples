#include <iostream>
#include <vector>
#include <limits>
#include "MinHeap.h"
using namespace std;

  /*
  *   MinHeap: constructor
  *   Action: creates heap from null.
  */
  MinHeap::MinHeap() {
    heap = vector<int>();
  }

  /*
  *   MinHeap: constructor
  *   Action: builds heap from existing array - not sorted.
  */
  MinHeap::MinHeap(const vector<int> &arr) {
    buildHeap(arr);
  }

  /*
  *   buildHeap:
  *   Action: Given a vector array of integers, sorts them into a proper heap
  */
  void MinHeap::buildHeap(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      insert(arr[i]);
    }
  }

  /*
  *   insert:
  *   Action: given a new integer i, insert the integer into the correct place
  *     in the heap, and make sure the heap is correctly sorted
  */
  void MinHeap::insert(int i) {
    heap.push_back(numeric_limits<int>::max());
    bubbleUp(heap.size() - 1, i);
  }

  /*
  *   peekMin:
  *   Action: returns the value of the smallest number in the heap without
  *     removing it
  */
  int MinHeap::peekMin() {
    if (heap.size() > 0) {
      return heap[0];
    }
    return numeric_limits<int>::min();
  }

  /*
  *   getMin:
  *   Action: removes and returns the smallest object in the heap, resorting
  *     the rest of the heap as appropriate (bubble up)
  */
  int MinHeap::getMin() {
    int root;
    if (heap.size() > 0) {
      root = heap[0];

      // switch last with root, delete last
      heap[0] = heap[heap.size() - 1];
      heap.pop_back();

      bubbleDown(0); // sort down
    }
    else {
      root = numeric_limits<int>::min();
    }

    return root;
  }

  /*
  *   getSize:
  *   Action: returns the number of elements in the heap
  */
  int MinHeap::getSize() const {
    return heap.size();
  }

  /*
  *   operator=:
  *   Action: compares two heaps
  */
  bool MinHeap::operator==(const MinHeap &newHeap) const {
    bool equal = true;
    if (newHeap.getSize() != getSize()) {
      equal = false;
    }
    else {
      for (int i; i < getSize(); i++) {
        if (newHeap.getElem(i) != heap[i]) {
          return false;
        }
      }
    }
    return equal;
  }

  /*
  *   getElem():
  *   Action: returns the value of the given element
  */
  int MinHeap::getElem(int v) const {
    return heap[v];
  }

  /*
  *   swap:
  *   Action: given the location of two values within the heap, the items are
  *     swapped.
  */
  void MinHeap::swap(int x, int y) {
    int temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
  }

  /*
  *   getLeft:
  *   Action: given a vector in the heap, the location of the left child is
  *     returned
  */
  int MinHeap::getLeft(int v) {
    return 2 * v + 1;
  }

  /*
  *   getRight:
  *   Action: given a vector in the heap, the location of the right child is
  *     returned
  */
  int MinHeap::getRight(int v) {
    return 2 * v + 2;
  }

  /*
  *   getParent:
  *   Action: given a vector in the heap, the location of the parent is
  *     returned.
  */
  int MinHeap::getParent(int v) {
    return v / 2;
  }

  /*
  *   bubbleUp:
  *   Action: given a location in the heap and a value, compare the two values
  *     until you find where the value belongs.
  */
  void MinHeap::bubbleUp(int v, int k) {
    if (k < heap[v]) {
      heap[v] = k;
      int par = getParent(v - 1);
      while (heap[par] > heap[v]) {
        swap(v, par);
        v = par;
        par = getParent(v - 1);
      }
    }
  }

  /*
  *   bubbleDown:
  *   Action: given the location of a vertext, bubble it down the heap into the
  *     correct location.
  */
  void MinHeap::bubbleDown(int v) {
    int ri = getRight(v);
    int li = getLeft(v);

    if (heap.size() <= 1) {
      return;
    }

    int largest = -1;
    if (li < heap.size() && heap[li] < heap[v]) {
      largest = li;
    }
    else {
      largest = v;
    }

    if (ri < heap.size() && heap[ri] < heap[largest]) {
      largest = ri;
    }

    if (largest != v) {
      swap(v, largest);
      bubbleDown(largest);
    }
  }
