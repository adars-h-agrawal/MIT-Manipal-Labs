import java.util.Scanner;

// Base class Game
class Game {
    public void type() {
        System.out.println("Indoor & outdoor games");
    }
}

// Subclass Cricket
class Cricket extends Game {
    @Override
    public void type() {
        System.out.println("Cricket is an outdoor game");
    }
}

// Subclass Chess
class Chess extends Game {
    @Override
    public void type() {
        System.out.println("Chess is an indoor game");
    }
}

// Main class to demonstrate dynamic method dispatch
public class Main_a {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a game type to display:");
        System.out.println("1. Cricket");
        System.out.println("2. Chess");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        Game game;

        switch (choice) {
            case 1:
                game = new Cricket();
                break;
            case 2:
                game = new Chess();
                break;
            default:
                System.out.println("Invalid choice.");
                scanner.close();
                return;
        }

        game.type(); // Dynamic method dispatch
        scanner.close();
    }
}
