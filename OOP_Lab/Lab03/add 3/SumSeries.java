import java.util.Scanner;

public class SumSeries {
    public static double sumSeries(int n) {
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += 1 / Math.pow(i, i);
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of terms: ");
        int n = scanner.nextInt();
        scanner.close();

        double sumValue = sumSeries(n);
        System.out.println("The value of the series sum is: " + sumValue);
    }
}
