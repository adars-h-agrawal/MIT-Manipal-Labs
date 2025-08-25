import java.util.Scanner;

// Abstract class Shape
abstract class Shape {
    abstract double calculateArea();
}

// Square class
class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public double calculateArea() {
        return side * side;
    }
}

// Triangle class
class Triangle extends Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    public double calculateArea() {
        return 0.5 * base * height;
    }
}

// Main class
public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter side of the square:");
        double side = sc.nextDouble();
        Square square = new Square(side);

        System.out.println("Enter base and height of the triangle:");
        double base = sc.nextDouble();
        double height = sc.nextDouble();
        Triangle triangle = new Triangle(base, height);

        System.out.println("Area of Square: " + square.calculateArea());
        System.out.println("Area of Triangle: " + triangle.calculateArea());
    }
}
