import java.util.Scanner;

public class ExpressionEvaluation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input values for a and b
        System.out.print("Enter the value of a: ");
        int a = scanner.nextInt();

        System.out.print("Enter the value of b: ");
        int b = scanner.nextInt();

        // Expression a: (a << 2) + (b >> 2)
        int resultA = (a << 2) + (b >> 2);
        System.out.println("Result of (a << 2) + (b >> 2): " + resultA);

        // Expression b: (b > 0)
        boolean resultB = (b > 0);
        System.out.println("Result of (b > 0): " + resultB);

        // Expression c: (a + b * 100) / 10
        int resultC = (a + b * 100) / 10;
        System.out.println("Result of (a + b * 100) / 10: " + resultC);

        // Expression d: a & b
        int resultD = a & b;
        System.out.println("Result of a & b: " + resultD);

        scanner.close();
    }
}
