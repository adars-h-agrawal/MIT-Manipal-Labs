import java.util.Scanner;

// Sports interface
interface Sports {
    void getNumberOfGoals();
    void dispTeam();
}

// Hockey class
class Hockey implements Sports {
    private int goals;
    private String winningTeam;

    public Hockey(int goals, String winningTeam) {
        this.goals = goals;
        this.winningTeam = winningTeam;
    }

    public void getNumberOfGoals() {
        System.out.println("Hockey Goals: " + goals);
    }

    public void dispTeam() {
        System.out.println("Winning Hockey Team: " + winningTeam);
    }
}

// Football class
class Football implements Sports {
    private int goals;
    private String winningTeam;

    public Football(int goals, String winningTeam) {
        this.goals = goals;
        this.winningTeam = winningTeam;
    }

    public void getNumberOfGoals() {
        System.out.println("Football Goals: " + goals);
    }

    public void dispTeam() {
        System.out.println("Winning Football Team: " + winningTeam);
    }
}

// Main class
public class Main3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Hockey input
        System.out.println("Enter hockey goals and winning team:");
        int hockeyGoals = sc.nextInt();
        sc.nextLine(); // consume newline
        String hockeyTeam = sc.nextLine();
        Hockey hockey = new Hockey(hockeyGoals, hockeyTeam);

        // Football input
        System.out.println("Enter football goals and winning team:");
        int footballGoals = sc.nextInt();
        sc.nextLine(); // consume newline
        String footballTeam = sc.nextLine();
        Football football = new Football(footballGoals, footballTeam);

        // Display results
        System.out.println("\nHockey Match Results:");
        hockey.getNumberOfGoals();
        hockey.dispTeam();

        System.out.println("\nFootball Match Results:");
        football.getNumberOfGoals();
        football.dispTeam();
    }
}
