import java.util.Scanner;

public class StringComparisonMenu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter first string: ");
        String str1 = scanner.nextLine();
        System.out.println("Enter second string: ");
        String str2 = scanner.nextLine();

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Compare two strings");
            System.out.println("2. Convert case");
            System.out.println("3. Check substring");
            System.out.println("4. Replace substring with 'Hello'");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.println("Strings are equal: " + str1.equals(str2));
                    break;
                case 2:
                    System.out.println("Converted case: " + 
                        str1.toLowerCase() + " | " + str1.toUpperCase());
                    break;
                case 3:
                    System.out.println("Is second string a substring of first: " + str1.contains(str2));
                    break;
                case 4:
                    if (str1.contains(str2)) {
                        String replacedString = str1.replace(str2, "Hello");
                        System.out.println("Modified string: " + replacedString);
                    } else {
                        System.out.println("Second string is not a substring of the first.");
                    }
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}