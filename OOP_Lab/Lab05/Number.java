import java.util.Scanner;

class Number {
    private double num;

    // Constructor to initialize the number
    public Number(double num) {
        this.num = num;
    }

    // Method to check if the number is zero
    public boolean isZero() {
        return num == 0;
    }

    // Method to check if the number is positive
    public boolean isPositive() {
        return num > 0;
    }

    // Method to check if the number is negative
    public boolean isNegative() {
        return num < 0;
    }

    // Method to check if the number is odd
    public boolean isOdd() {
        return num % 2 != 0;
    }

    // Method to check if the number is even
    public boolean isEven() {
        return num % 2 == 0;
    }

    // Method to check if the number is prime
    public boolean isPrime() {
        if (num < 2 || num != Math.floor(num)) 
            return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // Method to check if the number is Armstrong
    public boolean isArmstrong() {
        int sum = 0, temp, digits = 0;
        temp = (int) num;
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
        temp = (int) num;
        while (temp != 0) {
            int digit = temp % 10;
            sum += Math.pow(digit, digits);
            temp /= 10;
        }
        return sum == num;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        double input = scanner.nextDouble();

        Number number = new Number(input);

        System.out.println("Is Zero: " + number.isZero());
        System.out.println("Is Positive: " + number.isPositive());
        System.out.println("Is Negative: " + number.isNegative());
        System.out.println("Is Odd: " + number.isOdd());
        System.out.println("Is Even: " + number.isEven());
        System.out.println("Is Prime: " + number.isPrime());
        System.out.println("Is Armstrong: " + number.isArmstrong());

        scanner.close();
    }
}
