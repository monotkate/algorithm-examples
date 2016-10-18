import java.util.*;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class BinarySearch {


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

    // Find Element
    int target = Integer.parseInt(args[0]);
    int loc = binSearch(array, target, 0, array.size());
    if (loc >= 0) {
      System.out.printf("Target: %d, Location: %d\n", target, loc);
    }
    else {
      System.out.println("Target was not found");
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

  private static int binSearch(List<Integer> array, int target, int first, int last) {
    int size = last - first;
    if (size < 1) {
      return -1;
    }

    int mid = (int)Math.floor(size/2) + first;
    if (target == array.get(mid)) {
      return mid;
    }
    else if (target > array.get(mid)) {
      return binSearch(array, target, mid + 1, last);
    }
    else {
      return binSearch(array, target, first, mid - 1);
    }
  }



  /*
  *   readArray: compiles array from test file
  *     inputs: f - Scanner for the input file
  *     outputs: returns a list of integers from the input file
  */

  private static List<Integer> readArray(Scanner f) {
    List<Integer> arr = new ArrayList<Integer>();

    while (f.hasNext()) {
      int n = f.nextInt();
      arr.add(n);
    }

    Collections.sort(arr);

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
