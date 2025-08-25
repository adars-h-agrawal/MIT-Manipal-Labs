import java.util.Scanner;
import java.util.EmptyStackException;

class GenericStack<T> {
    private Object[] elements;
    private int size = 0;
    private static final int DEFAULT_CAPACITY = 10;

    public GenericStack() {
        elements = new Object[DEFAULT_CAPACITY];
    }

    public void push(T item) {
        if (size == elements.length) {
            resize();
        }
        elements[size++] = item;
    }

    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        T item = (T) elements[--size];
        elements[size] = null; // Avoid memory leak
        return item;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private void resize() {
        Object[] newArray = new Object[elements.length * 2];
        System.arraycopy(elements, 0, newArray, 0, elements.length);
        elements = newArray;
    }

    public int getSize() {
        return size;
    }
}

class Student {
    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{name='" + name + "', age=" + age + "}";
    }
}

class Employee {
    String name;
    double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Employee{name='" + name + "', salary=" + salary + "}";
    }
}

public class GenericStackDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Stack for Students
        GenericStack<Student> studentStack = new GenericStack<>();
        System.out.println("Enter number of students:");
        int studentCount = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < studentCount; i++) {
            System.out.println("Enter student name:");
            String name = scanner.nextLine();
            System.out.println("Enter student age:");
            int age = scanner.nextInt();
            scanner.nextLine(); // Consume newline
            studentStack.push(new Student(name, age));
        }

        System.out.println("Students in stack:");
        while (!studentStack.isEmpty()) {
            System.out.println(studentStack.pop());
        }

        // Stack for Employees
        GenericStack<Employee> employeeStack = new GenericStack<>();
        System.out.println("Enter number of employees:");
        int employeeCount = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        for (int i = 0; i < employeeCount; i++) {
            System.out.println("Enter employee name:");
            String name = scanner.nextLine();
            System.out.println("Enter employee salary:");
            double salary = scanner.nextDouble();
            scanner.nextLine(); // Consume newline
            employeeStack.push(new Employee(name, salary));
        }

        System.out.println("Employees in stack:");
        while (!employeeStack.isEmpty()) {
            System.out.println(employeeStack.pop());
        }

        scanner.close();
    }
}

/*
Enter number of students:
2
Enter student name:
Alice
Enter student age:
20
Enter student name:
Bob
Enter student age:
22
Students in stack:
Student{name='Bob', age=22}
Student{name='Alice', age=20}
Enter number of employees:
2
Enter employee name:
Charlie
Enter employee salary:
50000
Enter employee name:
Diana
Enter employee salary:
60000
Employees in stack:
Employee{name='Diana', salary=60000.0}
Employee{name='Charlie', salary=50000.0}
 */