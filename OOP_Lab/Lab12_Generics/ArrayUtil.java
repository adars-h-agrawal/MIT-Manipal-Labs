import java.util.Arrays;
import java.util.Scanner;

public class ArrayUtil {

    public static <T> void swap(T[] array, int index1, int index2) {
        if (array == null) {
            throw new IllegalArgumentException("Array cannot be null");
        }
        if (index1 < 0 || index1 >= array.length || index2 < 0 || index2 >= array.length) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input array size
        System.out.print("Enter the number of elements in the array: ");
        int size = scanner.nextInt();
        
        // Input array elements
        Integer[] intArray = new Integer[size];
        System.out.println("Enter " + size + " integer elements:");
        for (int i = 0; i < size; i++) {
            intArray[i] = scanner.nextInt();
        }
        
        // Display the array before swapping
        System.out.println("Before swap: " + Arrays.toString(intArray));
        
        // Input indices to swap
        System.out.print("Enter the first index to swap: ");
        int index1 = scanner.nextInt();
        System.out.print("Enter the second index to swap: ");
        int index2 = scanner.nextInt();
        
        // Swap the elements
        swap(intArray, index1, index2);
        
        // Display the array after swapping
        System.out.println("After swap: " + Arrays.toString(intArray));
        
        scanner.close();
    }
}

/*
Enter the number of elements in the array: 5
Enter 5 integer elements:
1
2
3
4
5
Before swap: [1, 2, 3, 4, 5]
Enter the first index to swap: 1
Enter the second index to swap: 3
After swap: [1, 4, 3, 2, 5]
*/