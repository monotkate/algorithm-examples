QUICKSORT:
==========
Quicksort is an efficient sorting algorithm.

Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays.

The steps are:
- Pick an element, called a pivot, from the array.
- Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
- Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
The base case of the recursion is arrays of size zero or one, which never need to be sorted.

There are several ways to choose the pivot. The implementation of the code uses the Lotus partition scheme where the pivot is always the last value of the list.

Running Instructions:
=====================
- Run the code with 'Test/test0.txt' file:
	- make run

Testing:
========
- Install dependencies:
	- make setup
- Run:
	- make test



