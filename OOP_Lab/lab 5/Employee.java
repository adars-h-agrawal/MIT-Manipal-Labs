import java.util.Scanner;

class Employee {
    // Data members
    String name, city;
    double basicSalary, daPercentage, hraPercentage, totalSalary;

    // Method to get data from the user
    void getdata() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter employee name: ");
        name = scanner.nextLine();

        System.out.print("Enter city: ");
        city = scanner.nextLine();

        System.out.print("Enter basic salary: ");
        basicSalary = scanner.nextDouble();

        System.out.print("Enter DA%: ");
        daPercentage = scanner.nextDouble();

        System.out.print("Enter HRA%: ");
        hraPercentage = scanner.nextDouble();
    }

    // Method to calculate the total salary
    void calculate() {
        totalSalary = basicSalary + (basicSalary * daPercentage / 100) + (basicSalary * hraPercentage / 100);
    }

    // Method to display the employee details and total salary
    void display() {
        System.out.println("\nEmployee Details:");
        System.out.println("Name: " + name);
        System.out.println("City: " + city);
        System.out.println("Basic Salary: " + basicSalary);
        System.out.println("Total Salary: " + totalSalary);
    }

    public static void main(String[] args) {
        // Create an object of Employee class
        Employee emp = new Employee();

        // Get data from the user
        emp.getdata();

        // Calculate the total salary
        emp.calculate();

        // Display the employee details and total salary
        emp.display();
    }
}
