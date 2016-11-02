package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// struct to list
type Sort struct {
	List []int
}

/*
* 	Swap two values in array
* 		Input:
*			- i and j: indexes in the list to swap
 */
func (s *Sort) Swap(i, j int) {
	s.List[j], s.List[i] = s.List[i], s.List[j]
}

/* 	Choose the pivot as the last value of the list
*	and organize the list with all smaller values
*	than the pivot in left side of the list
*	and all greater values in right side
*		Input:
*			- start and end: limits of the list where
*				the function will work
*		Output:
*			- Pivot index
 */
func (s *Sort) Partition(start, end int) int {
	pivot := s.List[end-1]
	i := start
	for j := start; j < end-1; j++ {
		if s.List[j] <= pivot {
			s.Swap(i, j)
			i++
		}
	}
	s.Swap(i, end-1)
	return i
}

/*
* Recursively apply quicksort to the sub-array of elements
* with smaller values and separately to the sub-array of elements
* with greater values
* 	Input:
*		- start and end: limits of the list where
*			the function will work
 */
func (s *Sort) Quicksort(start, end int) {
	if start < end {
		pivot := s.Partition(start, end)
		s.Quicksort(start, pivot)
		s.Quicksort(pivot+1, end)
	}
}

/*
	main: reads test data in and sorts the values
*/
func main() {
	listSort := Sort{}

	// open file
	file, err := os.Open("../Test/test0.txt")
	if err != nil {
		panic(err)
	}
	// Read the file and convert to int
	r := bufio.NewReader(file)
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	for scanner.Scan() {
		value, err := strconv.Atoi(scanner.Text())
		if err != nil {
			panic(err)
		}
		listSort.List = append(listSort.List, value)
	}

	// prints the original list
	fmt.Println("Start list: ", listSort.List)
	// sorts the values with Quicksort
	listSort.Quicksort(0, len(listSort.List))
	// prints the sorted list
	fmt.Println("Sorted list: ", listSort.List)
}
