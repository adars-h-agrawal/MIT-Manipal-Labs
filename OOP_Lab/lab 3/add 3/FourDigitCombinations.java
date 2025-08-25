import java.util.Scanner;

public class FourDigitCombinations {

    // Method to print combinations with duplication allowed
    public static void printWithDuplication() {
        System.out.println("Combinations with duplication allowed:");
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                for (int k = 1; k <= 4; k++) {
                    for (int l = 1; l <= 4; l++) {
                        System.out.printf("%d%d%d%d\n", i, j, k, l);
                    }
                }
            }
        }
    }

    // Method to print combinations without duplication allowed
    public static void printWithoutDuplication() {
        System.out.println("Combinations without duplication allowed:");
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                if (j == i) continue; // Ensure j is different from i
                for (int k = 1; k <= 4; k++) {
                    if (k == i || k == j) continue; // Ensure k is different from i and j
                    for (int l = 1; l <= 4; l++) {
                        if (l == i || l == j || l == k) continue; // Ensure l is different from i, j, and k
                        System.out.printf("%d%d%d%d\n", i, j, k, l);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            // Display menu
            System.out.println("\nMenu:");
            System.out.println("1. Generate combinations with duplication allowed");
            System.out.println("2. Generate combinations without duplication allowed");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    printWithDuplication();
                    break;
                case 2:
                    printWithoutDuplication();
                    break;
                case 3:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        } while (choice != 3);

        scanner.close();
    }
}
