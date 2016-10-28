package main

import (
	. "gopkg.in/check.v1"
	"testing"
)

func Test(t *testing.T) { TestingT(t) }

type SortSuite struct{}

var _ = Suite(&SortSuite{})

func (s *SortSuite) TestQuickSort(c *C) {
	l := Sort{
		List: []int{2, 5, 3, 9, 8, 21, 10, 1},
	}
	expected_list := []int{1, 2, 3, 5, 8, 9, 10, 21}
	l.Quicksort(0, len(l.List))
	c.Check(l.List, DeepEquals, expected_list)
}

func (s *SortSuite) TestQuickSortNegativeNumber(c *C) {
	l := Sort{
		List: []int{2, 5, 3, 9, 8, 21, -10, -1},
	}
	expected_list := []int{-10, -1, 2, 3, 5, 8, 9, 21}
	l.Quicksort(0, len(l.List))
	c.Check(l.List, DeepEquals, expected_list)
}

func (s *SortSuite) TestQuickSortRepeatedNumber(c *C) {
	l := Sort{
		List: []int{2, 5, 3, 9, 8, 21, -10, -1, 9},
	}
	expected_list := []int{-10, -1, 2, 3, 5, 8, 9, 9, 21}
	l.Quicksort(0, len(l.List))
	c.Check(l.List, DeepEquals, expected_list)
}

func (s *SortSuite) TestPartition(c *C) {
	l := Sort{
		List: []int{2, 5, 3, 9, 8, 21, -10, -1, 9},
	}
	expected_list := []int{2, 5, 3, 9, 8, -10, -1, 9, 21}
	pivot := l.Partition(0, len(l.List))
	c.Check(l.List, DeepEquals, expected_list)
	c.Check(pivot, Equals, 7)
}

func (s *SortSuite) TestPartitionPivotNegativeNumber(c *C) {
	l := Sort{
		List: []int{2, 5, 3, 9, 8, 21, -10, -1, -9},
	}
	expected_list := []int{-10, -9, 3, 9, 8, 21, 2, -1, 5}
	pivot := l.Partition(0, len(l.List))
	c.Check(l.List, DeepEquals, expected_list)
	c.Check(pivot, Equals, 1)
}

func (s *SortSuite) TestSwap(c *C) {
	l := Sort{
		List: []int{2, 3, 5},
	}
	l.Swap(0, 2)
	c.Check(l.List, DeepEquals, []int{5, 3, 2})
}
