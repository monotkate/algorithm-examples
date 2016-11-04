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
  // MinHeap::MinHeap(const vector<int> &arr) {
  //   buildHeap(arr);
  // }

  /*
  *   buildHeap:
  *   Action: Given a vector array of integers, sorts them into a proper heap
  */
  // void MinHeap::buildHeap(vector<int> arr) {
  //   for (int i = 0; i < arr.size(); i++) {
  //     //minHeapify(arr[i]);
  //   }
  // }

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
    return -1;
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
      swap(0, heap.size() - 1);
      bubbleDown(0);
    }
    else {
      root = -1;
    }

    return root;
  }

  void MinHeap::printHeap() {
    for (int i = 0; i < heap.size(); i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
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
      while (v > 0 && heap[par] > heap[v]) {
        swap(v, par);
        v = par;
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
