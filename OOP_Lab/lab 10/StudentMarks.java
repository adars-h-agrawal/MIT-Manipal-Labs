import java.util.Scanner;

public class StudentMarks {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Enter student's Name: ");
            String name = scanner.nextLine();

            System.out.print("Enter Roll Number: ");
            String rollNumber = scanner.nextLine();

            System.out.print("Enter Marks for Subject 1: ");
            double marks1 = Double.parseDouble(scanner.nextLine());
            System.out.print("Enter Marks for Subject 2: ");
            double marks2 = Double.parseDouble(scanner.nextLine());
            System.out.print("Enter Marks for Subject 3: ");
            double marks3 = Double.parseDouble(scanner.nextLine());

            double percentage = (marks1 + marks2 + marks3) / 3;
            char grade;

            if (percentage >= 90) grade = 'A';
            else if (percentage >= 75) grade = 'B';
            else if (percentage >= 50) grade = 'C';
            else grade = 'D';

            System.out.println("Name: " + name);
            System.out.println("Roll Number: " + rollNumber);
            System.out.println("Percentage: " + percentage + "%");
            System.out.println("Grade: " + grade);
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid number format for marks.");
        } finally {
            scanner.close();
        }
    }
}
