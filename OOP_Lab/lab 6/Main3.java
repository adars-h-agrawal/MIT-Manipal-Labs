import java.util.Scanner;

// Base class Bank
abstract class Bank {
    public abstract double getRateOfInterest();
}

// Subclass SBI
class SBI extends Bank {
    @Override
    public double getRateOfInterest() {
        return 8.0; // SBI provides 8% interest
    }
}

// Subclass ICICI
class ICICI extends Bank {
    @Override
    public double getRateOfInterest() {
        return 7.0; // ICICI provides 7% interest
    }
}

// Subclass AXIS
class AXIS extends Bank {
    @Override
    public double getRateOfInterest() {
        return 9.0; // AXIS provides 9% interest
    }
}

// Main class with user input
public class Main3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a bank to check interest rates:");
        System.out.println("1. SBI\n2. ICICI\n3. AXIS");
        System.out.print("Enter your choice: ");
        int choice = scanner.nextInt();

        Bank bank;
        switch (choice) {
            case 1:
                bank = new SBI();
                break;
            case 2:
                bank = new ICICI();
                break;
            case 3:
                bank = new AXIS();
                break;
            default:
                System.out.println("Invalid choice.");
                scanner.close();
                return;
        }

        System.out.println("Rate of Interest: " + bank.getRateOfInterest() + "%");
        scanner.close();
    }
}
