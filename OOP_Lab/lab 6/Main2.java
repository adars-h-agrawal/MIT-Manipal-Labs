import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Base class Student
class Student {
    private String regNumber;
    private String name;
    private int age;

    public Student(String regNumber, String name, int age) {
        this.regNumber = regNumber;
        this.name = name;
        this.age = age;
    }

    public String getRegNumber() {
        return regNumber;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public void displayStudentInfo() {
        System.out.println("Registration Number: " + regNumber);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

// Subclass UGStudent
class UGStudent extends Student {
    private int semester;
    private double fees;

    public UGStudent(String regNumber, String name, int age, int semester, double fees) {
        super(regNumber, name, age);
        this.semester = semester;
        this.fees = fees;
    }

    public int getSemester() {
        return semester;
    }

    public double getFees() {
        return fees;
    }

    @Override
    public void displayStudentInfo() {
        super.displayStudentInfo();
        System.out.println("Semester: " + semester);
        System.out.println("Fees: " + fees);
    }
}

// Subclass PGStudent
class PGStudent extends Student {
    private int semester;
    private double fees;

    public PGStudent(String regNumber, String name, int age, int semester, double fees) {
        super(regNumber, name, age);
        this.semester = semester;
        this.fees = fees;
    }

    public int getSemester() {
        return semester;
    }

    public double getFees() {
        return fees;
    }

    @Override
    public void displayStudentInfo() {
        super.displayStudentInfo();
        System.out.println("Semester: " + semester);
        System.out.println("Fees: " + fees);
    }
}

// Main class with user input
public class Main2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        List<UGStudent> ugStudents = new ArrayList<>();
        List<PGStudent> pgStudents = new ArrayList<>();

        while (true) {
            System.out.println("\n1. Add UG Student\n2. Add PG Student\n3. Display UG Students\n4. Display PG Students\n5. Exit");
            System.out.print("Choose an option: ");
            int option = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (option) {
                case 1:
                    System.out.print("Enter UG Student Registration Number: ");
                    String ugRegNumber = scanner.nextLine();
                    System.out.print("Enter UG Student Name: ");
                    String ugName = scanner.nextLine();
                    System.out.print("Enter UG Student Age: ");
                    int ugAge = scanner.nextInt();
                    System.out.print("Enter UG Student Semester: ");
                    int ugSemester = scanner.nextInt();
                    System.out.print("Enter UG Student Fees: ");
                    double ugFees = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline
                    UGStudent ugStudent = new UGStudent(ugRegNumber, ugName, ugAge, ugSemester, ugFees);
                    ugStudents.add(ugStudent);
                    break;
                case 2:
                    System.out.print("Enter PG Student Registration Number: ");
                    String pgRegNumber = scanner.nextLine();
                    System.out.print("Enter PG Student Name: ");
                    String pgName = scanner.nextLine();
                    System.out.print("Enter PG Student Age: ");
                    int pgAge = scanner.nextInt();
                    System.out.print("Enter PG Student Semester: ");
                    int pgSemester = scanner.nextInt();
                    System.out.print("Enter PG Student Fees: ");
                    double pgFees = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline
                    PGStudent pgStudent = new PGStudent(pgRegNumber, pgName, pgAge, pgSemester, pgFees);
                    pgStudents.add(pgStudent);
                    break;
                case 3:
                    System.out.println("\nUG Students:");
                    for (UGStudent student : ugStudents) {
                        student.displayStudentInfo();
                        System.out.println();
                    }
                    break;
                case 4:
                    System.out.println("\nPG Students:");
                    for (PGStudent student : pgStudents) {
                        student.displayStudentInfo();
                        System.out.println();
                    }
                    break;
                case 5:
                    System.out.println("Exiting.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option.");
            }
        }
    }
}