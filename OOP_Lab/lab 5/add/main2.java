import java.util.Arrays;
import java.util.Scanner;

class ArrayOperations {
    int[] arr = new int[10];

    // Method to input values into the array
    void inputValues() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 integers:");
        for (int i = 0; i < 10; i++) {
            arr[i] = sc.nextInt();
        }
    }

    // Method to display the values
    void displayValues() {
        System.out.println("Array values:");
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    // Method to display the largest value
    void displayLargest() {
        int largest = Arrays.stream(arr).max().getAsInt();
        System.out.println("Largest value: " + largest);
    }

    // Method to display the average value
    void displayAverage() {
        double average = Arrays.stream(arr).average().getAsDouble();
        System.out.println("Average value: " + average);
    }

    // Method to sort the array in ascending order
    void sortArray() {
        Arrays.sort(arr);
        System.out.println("Array sorted in ascending order:");
        displayValues();
    }

    public static void main2(String[] args) {
        ArrayOperations arrayOps = new ArrayOperations();
        arrayOps.inputValues();
        arrayOps.displayValues();
        arrayOps.displayLargest();
        arrayOps.displayAverage();
        arrayOps.sortArray();
    }
}
