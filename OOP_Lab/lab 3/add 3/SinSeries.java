import java.util.Scanner;

public class SinSeries {
    public static double factorial(int n) {
        double fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    public static double sinSeries(double x, int terms) {
        double sum = 0;
        for (int i = 0; i < terms; i++) {
            int sign = (i % 2 == 0) ? 1 : -1;
            int power = 2 * i + 1;
            sum += sign * (Math.pow(x, power) / factorial(power));
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of x (in radians): ");
        double x = scanner.nextDouble();
        System.out.print("Enter the number of terms: ");
        int terms = scanner.nextInt();
        scanner.close();

        double sinValue = sinSeries(x, terms);
        System.out.println("The value of Sin(" + x + ") is: " + sinValue);
    }
}
