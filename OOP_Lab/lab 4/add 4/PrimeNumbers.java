public class PrimeNumbers {
    // Method to check if a number is prime
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true; // 2 is the only even prime number
        if (num % 2 == 0) return false; // Other even numbers are not prime
        for (int i = 3; i <= Math.sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int[] array = {10, 15, 23, 4, 17, 8, 31}; // Example array

        System.out.println("Prime numbers in the array:");
        for (int num : array) {
            if (isPrime(num)) {
                System.out.print(num + " ");
            }
        }
    }
}
