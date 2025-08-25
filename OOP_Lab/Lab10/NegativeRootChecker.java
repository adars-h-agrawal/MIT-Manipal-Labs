import java.util.Scanner;

public class NegativeRootChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number to find its square root: ");
        
        double number = scanner.nextDouble();
        
        if (number < 0) {
            System.out.println("Error: Cannot find the square root of a negative number.");
        } else {
            double root = Math.sqrt(number);
            System.out.println("Square root of " + number + " is: " + root);
        }
        
        scanner.close();
    }
}
