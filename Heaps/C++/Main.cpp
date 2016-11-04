#include <iostream>
#include <vector>
#include "MinHeap.h"
using namespace std;

int main() {
  MinHeap heap = MinHeap();
  heap.printHeap();

  heap.insert(1);
  heap.printHeap();

  heap.insert(3);
  heap.insert(-1);
  heap.printHeap();

  heap.insert(4);
  heap.insert(5);
  heap.insert(-5);
  heap.insert(1000);
  heap.printHeap();

  return 0;
}
