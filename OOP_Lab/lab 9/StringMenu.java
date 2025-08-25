import java.util.Scanner;

public class StringMenu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String input = scanner.nextLine();
        String reversed = new StringBuilder(input).reverse().toString(); // Initialize here

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Check if palindrome");
            System.out.println("2. Sort string in alphabetical order");
            System.out.println("3. Reverse the string");
            System.out.println("4. Concatenate original and reversed string");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    String isPalindrome = new StringBuilder(input).reverse().toString();
                    System.out.println("Is palindrome: " + input.equals(isPalindrome));
                    break;
                case 2:
                    char[] sorted = input.toCharArray();
                    java.util.Arrays.sort(sorted);
                    System.out.println("Sorted string: " + new String(sorted));
                    break;
                case 3:
                    System.out.println("Reversed string: " + reversed);
                    break;
                case 4:
                    System.out.println("Concatenated string: " + input + reversed);
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
