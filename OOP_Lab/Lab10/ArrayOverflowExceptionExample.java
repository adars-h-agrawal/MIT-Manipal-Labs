import java.util.Scanner;

public class ArrayOverflowExceptionExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        
        int size = scanner.nextInt();
        if (size > 10) {
            System.out.println("Error: Array size exceeds limit of 10.");
            return;
        }
        
        int[] numbers = new int[size];
        System.out.println("Array of size " + size + " created successfully.");
        scanner.close();
    }
}
