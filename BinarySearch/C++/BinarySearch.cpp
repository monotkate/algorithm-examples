#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// forward declarations
int binSearch(vector<int> array, int target, int first, int last);
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

  // Find Element
  int target = atoi(argv[1]);
  int loc = binSearch(array, target, 0, array.size());
  if (loc >= 0) {
    cout << "Target: " << target;
    cout << ", Location: " << loc << endl;
  }
  else {
    cout << "Target was not found" << endl;
  }
}



/*
*   binSearch: utilizes binary search recursively to find a target
*     inputs: array - contains integers to search sorted
*             target - the interger you want to find
*             first - the first index of the portion you're looking at
*             last - the last index of the portion you're looking at
*     outputs: returns the index of the target integer
*/

int binSearch(vector<int> array, int target, int first, int last) {
  int size = last - first;
  if (size < 1) {
    return -1;
  }

  int mid = (first + last)/2;
  if (target == array.at(mid)) {
    return mid;
  }
  else if (target > array.at(mid)) {
    return binSearch(array, target, mid + 1, last);
  }
  else {
    return binSearch(array, target, first, mid);
  }
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
    while ( getline (f,line) ) {
      array.push_back(stoi(line));
    }
    f.close();
  }
  sort(array.begin(), array.end());

  return array;
}



/*
*   printArray: prints contents of array to the CLI
*     inputs: arr - the array to print
*     outputs: none
*/

void printArray(vector<int> arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    if (i < arr.size() - 1) {
      cout << arr.at(i) << " ,";
    }
    else {
      cout << arr.at(i) << "]\n";
    }
  }
}
