#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../MinHeap.cpp"
#include <limits>
#include <vector>

TEST_CASE( "constructor operating correctly" ) {
  SECTION("builds empty heap") {
    MinHeap heap = MinHeap();
    REQUIRE(heap.getSize() == 0);
  }
}

TEST_CASE( "buildHeap() operating correctly" ) {
  SECTION("empty array returns empty heap") {
    vector<int> arr = vector<int>();

    MinHeap heap = MinHeap(arr);
    REQUIRE(heap.getSize() == 0);
  }

  SECTION("full array returns correct heap") {
    MinHeap heap = MinHeap();
    heap.insert(-5);
    heap.insert(3);
    heap.insert(-20);
    heap.insert(1);

    vector<int> arr = vector<int>();
    arr.push_back(-5);
    arr.push_back(3);
    arr.push_back(-20);
    arr.push_back(1);
    MinHeap heapNew = MinHeap(arr);

    REQUIRE(heap == (heapNew));
  }
}

TEST_CASE( "insert() operating correctly" ) {

  MinHeap heap = MinHeap();

  SECTION("initial value inserted in first elem") {
    heap.insert(1);
    REQUIRE(heap.getElem(0) == 1);
  }

  SECTION("multiple inserts end with correct positioning") {
    heap.insert(1);
    REQUIRE(heap.getElem(0) == 1);

    heap.insert(-1);
    REQUIRE(heap.getElem(0) == -1);
    REQUIRE(heap.getElem(1) == 1);

    heap.insert(5);
    heap.insert(0);
    REQUIRE(heap.getElem(0) == -1);
    REQUIRE(heap.getElem(1) == 0);
    REQUIRE(heap.getElem(2) == 5);
    REQUIRE(heap.getElem(3) == 1);
  }
}

TEST_CASE( "peekMin() operating correctly" ) {

  MinHeap heap = MinHeap();

  SECTION("empty heap returns int low limit") {
    REQUIRE(heap.peekMin() == numeric_limits<int>::min());
  }

  SECTION("heap with one element returns it") {
    heap.insert(5);
    REQUIRE(heap.peekMin() == 5);
  }

  SECTION("heap with several elements returns min") {
    heap.insert(4);
    heap.insert(1);
    heap.insert(200);
    REQUIRE(heap.peekMin() == 1);
  }

  SECTION("heap with several negative elements returns min") {
    heap.insert(-5);
    heap.insert(3);
    heap.insert(-20);
    REQUIRE(heap.peekMin() == -20);
  }
}

TEST_CASE( "getMin() operating correctly" ) {

  MinHeap heap = MinHeap();

  SECTION("empty heap returns int low limit") {
    REQUIRE(heap.getMin() == numeric_limits<int>::min());
  }

  SECTION("single elem heap returns that elem") {
    heap.insert(1);
    REQUIRE(heap.getMin() == 1);
    REQUIRE(heap.getSize() == 0);
  }

  SECTION("multiple elem heap returns min elem") {
    heap.insert(1);
    heap.insert(-5);
    heap.insert(2);
    int size = heap.getSize();
    REQUIRE(heap.getMin() == -5);
    REQUIRE(heap.getSize() == size - 1);

    size = heap.getSize();
    REQUIRE(heap.getMin() == 1);
    REQUIRE(heap.getSize() == size - 1);

    size = heap.getSize();
    REQUIRE(heap.getMin() == 2);
    REQUIRE(heap.getSize() == 0);
  }
}

TEST_CASE( "== operating correctly" ) {
  vector<int> arr = vector<int>();
  arr.push_back(5);
  arr.push_back(1);
  arr.push_back(-5);
  arr.push_back(2);

  MinHeap heap = MinHeap(arr);
  MinHeap newHeap = MinHeap(arr);

  SECTION("equal works") {
    bool equal = heap == newHeap;
    REQUIRE(equal == true);
  }

  SECTION("not equal works") {
    newHeap.insert(0);
    bool equal = heap == newHeap;
    REQUIRE(equal == false);
  }
}
