#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// forward declarations
int randomSel(vector<int> array, int target, int first, int last);
void swap(vector<int> &array, int x, int y);
vector<int> readArray(ifstream &f);
void printArray(vector<int> arr);


/*
*   main: reads test data in and outputs the location of the given target
*/
int main(int argc, char* argv[]) {
  //Open file
  ifstream f;
  f.open("../Test/test0.txt");
  if (f < 1) {
    cout << "File not found or not opened." << endl;
    return 0;
  }

  // Compile Array from file
  vector<int> array = readArray(f);
  printArray(array);

  vector<int> sorted(array);
  sort(sorted.begin(), sorted.end());
  printArray(sorted);

  // Find Element
  int target = -1;

  if (argv[1]) {
    target = atoi(argv[1]) - 1;
  }
  else {
    cout << "Please give a target with command\n";
    return -1;
  }

  if (target < 0 || target >= array.size()) {
    cout << "The target is not within range" << endl;
  }
  else {
    int ith = randomSel(array, target, 0, array.size());
    cout << "Target: " << target + 1 << ", ith: " << ith << endl;
  }
}



/*
*   randomSel: utilizes a pivot to find the ith smallest element in an
*             unsorted array.
*     inputs: array - contains integers to search unsorted
*             ith - the ith smallest element of the array
*             first - the first index of the portion you're looking at
*             last - the last index of the portion you're looking at
*     outputs: returns the value of the ith smallest element
*/

int randomSel(vector<int> array, int ith, int first, int last) {
  // Check the size, if one element, return that elem
  int size = last - first;
  if (size <= 0) {
    return array[first];
  }

  // Set pivot to a random value and swap with first elem
  int p = first + (rand() % size);
  swap(array, first, p);
  int pivot = array[first];

  // Pivot array around pivot value
  int i = first + 1;
  for (int j = i; j < last; j++) {
    if (array[j] < pivot) {
      swap(array, i, j);
      i++;
    }
  }

  // Swap the pivot into position and record new index
  p = i - 1;
  swap (array, first, p);

  // Compare the new location to the elem you're looking for, and recurse
  if (p == ith) {
    return pivot;
  }
  else if (p > ith) {
    return randomSel(array, ith, first, p);
  }
  else {
    return randomSel(array, ith, p + 1, last);
  }
}



/*
*   swap: swaps two elements in an array
*     inputs: array - contains integers to search unsorted
*             x - contains the index of the first element
*             y - contains the index of the second element
*     outputs: the array elements have now swapped index value
*/

void swap(vector<int> &array, int x, int y) {
  int temp = array[x];
  array[x] = array[y];
  array[y] = temp;
}



/*
*   readArray: compiles array from test file
*     inputs: f - Scanner for the input file
*     outputs: returns a sorted list of integers from the input file
*/

vector<int> readArray(ifstream &f) {
  string line;
  vector<int> array;

  if (f.is_open()) {
    while (getline(f, line)) {
      array.push_back(stoi(line));
    }
    f.close();
  }

  return array;
}



/*
*   printArray: prints contents of array to the CLI
*     inputs: arr - the array to print
*     outputs: none
*/

void printArray(vector<int> arr) {
  cout << "[ ";

  for (vector<int>::iterator i = arr.begin(); i != arr.end(); ++i) {
    cout << *i << " ";
  }

  cout << "]" << endl;
}
