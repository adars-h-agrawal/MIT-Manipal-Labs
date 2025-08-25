import java.util.Scanner;

class Complex {
    private int real;
    private int imaginary;

    // Constructor to initialize complex number
    public Complex(int real, int imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    // Method to add an integer to a complex number
    public Complex add(int num) {
        return new Complex(this.real + num, this.imaginary);
    }

    // Method to add two complex numbers
    public Complex add(Complex other) {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }

    // Method to display complex number
    public void display() {
        if (imaginary >= 0) {
            System.out.println(real + " + " + imaginary + "i");
        } else {
            System.out.println(real + " - " + (-imaginary) + "i");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // First complex number input
        System.out.print("Enter the first complex number (real imaginary): ");
        int r1 = scanner.nextInt();
        int i1 = scanner.nextInt();
        Complex c1 = new Complex(r1, i1);

        // Second complex number input
        System.out.print("Enter the second complex number (real imaginary): ");
        int r2 = scanner.nextInt();
        int i2 = scanner.nextInt();
        Complex c2 = new Complex(r2, i2);

        // Integer input
        System.out.print("Enter an integer to add to the first complex number: ");
        int num = scanner.nextInt();

        Complex result1 = c1.add(num); // Adding integer to complex number
        Complex result2 = c1.add(c2); // Adding two complex numbers

        System.out.print("Result of adding integer to complex number: ");
        result1.display();
        
        System.out.print("Result of adding two complex numbers: ");
        result2.display();

        scanner.close();
    }
}
