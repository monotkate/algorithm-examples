#include "MinHeap.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
  MinHeap heap = heap();

  testSwap();
}

int testSwap() {
  MinHeap heap = heap();
  heap.insert(1);
  heap.insert(2);
  heap.insert(3);
  heap.swap(0, 1);

  if(heap[0] == 2 && heap[1] == 1) {
    cout << "Swap PASS" << endl;
    return 0;
  }

  cout << "Swap did not accurately swap values in heap: " << endl;
  cout << "Expected: " << << endl;
  cout << "Actual: " << << endl;
  return -1;
}
