import java.util.*;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class RSelect {


  /*
  *   main: reads test data in and outputs the location of the given target
  */

  public static void main(String[] args) {
    // Open file
    Scanner f = null;

    try {
      f = new Scanner(new FileInputStream("../test/test1.txt"));
    }
    catch (FileNotFoundException e) {
      System.out.println("File not found or not opened.");
      System.exit(0);
    }

    // Compile Array from file
    List<Integer> array = readArray(f);

    // Sorted Array for checking answers
    List<Integer> sorted = new ArrayList<Integer>(array);
    Collections.sort(sorted);

    // Find the ith smallest element according to the target number
    int target = Integer.parseInt(args[0]) - 1;
    if (target < 0 || target >= array.size()) {
        System.out.println("The target is not within range");
    }
    else {
      int ith = randomSel(array, target, 0, array.size());
      System.out.printf("Target: %d element, ith: %d\n", target + 1, ith);
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

  private static int randomSel(List<Integer> array, int ith, int first, int last) {

    // Check the size, if one element, return that element
    int size = last - first;
    if (size <= 0) {
      return array.get(first);
    }

    // Set pivot to a random value and swap with first
    Random rand = new Random();
    int p = first + rand.nextInt(size);
    swap(array, first, p);
    int pivot = array.get(first);

    // Pivot array around pivot value
    int i = first + 1;
    for (int j = i; j < last; j++) {
      if (array.get(j) < pivot) {
        swap (array, i, j);
        i++;
      }
    }

    // Swap the pivot into position and record new index
    p = i - 1;
    swap (array, first, p);

    // Compare the new location to the element you're looking for, and recurse
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

  private static void swap(List<Integer> array, int x, int y) {
    int temp = array.get(x);
    array.set(x, array.get(y));
    array.set(y, temp);
  }



  /*
  *   readArray: compiles array from test file
  *     inputs: f - Scanner for the input file
  *     outputs: returns a list of integers from the input file unsorted
  */

  private static List<Integer> readArray(Scanner f) {
    List<Integer> arr = new ArrayList<Integer>();

    while (f.hasNext()) {
      int n = f.nextInt();
      arr.add(n);
    }

    return arr;
  }



  /*
  *   printArray: prints contents of array to the CLI
  *     inputs: arr - the array to print
  *     outputs: none
  */

  private static void printArray(List<Integer> arr) {
    System.out.printf("[");
    for (int i = 0; i < arr.size(); i++) {
      if (i < arr.size() - 1) {
        System.out.printf("%d, ", arr.get(i));
      }
      else {
        System.out.printf("%d]\n", arr.get(i));
      }
    }
  }
}
