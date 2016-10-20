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
      f = new Scanner(new FileInputStream("../test/test0.txt"));
    }
    catch (FileNotFoundException e) {
      System.out.println("File not found or not opened.");
      System.exit(0);
    }

    // Compile Array from file
    List<Integer> array = readArray(f);
    printArray(array);

    List<Integer> sorted = new ArrayList<Integer>(array);
    Collections.sort(sorted);
    printArray(sorted);

    // Find Element
    int target = Integer.parseInt(args[0]) - 1;
    int ith = randomSel(array, target, 0, array.size());
    // if (ith >= 0) {
      System.out.printf("Target: %d, ith: %d\n", target, ith);
      printArray(array);
    // }
    // else {
    //   System.out.println("Target was not found");
    // }

  }



  /*
  *   randomSel: utilizes a pivot to find the ith smallest element in an
  *             unsorted array.
  *     inputs: array - contains integers to search unsorted
  *             i - the ith element (that you want)
  *             first - the first index of the portion you're looking at
  *             last - the last index of the portion you're looking at
  *     outputs: returns the index of the ith smallest element
  */

  private static int randomSel(List<Integer> array, int ith, int first, int last) {
    printArray(array);

    int size = last - first;
    if (size <= 0) {
      return array.get(first);
    }

    int p = (int)Math.floor(size/2) + first;
    // int pivot = first;

    swap(array, first, p);
    int pivot = array.get(first);
    int i = first + 1;
    for (int j = i; j < last; j++) {
      if (array.get(j) < pivot) {
        swap (array, i, j);
        i++;
      }
    }
    swap (array, first, i - 1);

    if ((i - 1) == ith) {
      return pivot;
    }
    else if ((i - 1) > ith) {
      return randomSel(array, ith, first, i - 2);
    }
    else {
      return randomSel(array, ith, i, last);
    }
  }

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
        System.out.printf("%d", arr.get(i));
      }
    }
    System.out.printf("]\n");
  }
}
