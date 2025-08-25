import java.util.Scanner;

// Base class Bike
class Bike {
    int speedLimit = 100; // Speed limit for Bike
    
    public void run() {
        System.out.println("Bike speed limit is " + speedLimit + " km/h");
    }
}

// Subclass Splendar
class Splendar extends Bike {
    int speedLimit = 80; // Speed limit for Splendar
    
    @Override
    public void run() {
        System.out.println("Splendar speed limit is " + speedLimit + " km/h");
    }
}

// Main class to demonstrate runtime polymorphism
public class Main_b {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a type of vehicle:");
        System.out.println("1. Bike");
        System.out.println("2. Splendar");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();

        Bike bike;

        switch (choice) {
            case 1:
                bike = new Bike();
                break;
            case 2:
                bike = new Splendar();
                break;
            default:
                System.out.println("Invalid choice.");
                scanner.close();
                return;
        }

        bike.run(); // Dynamic method dispatch

        // Check speed limit via data members
        System.out.println("Speed limit from data member: " + bike.speedLimit + " km/h");

        scanner.close();
    }
}
