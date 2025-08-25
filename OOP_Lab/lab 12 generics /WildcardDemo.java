import java.util.ArrayList;
import java.util.List;

public class WildcardDemo {

    // Method to print elements of a list using a wildcard
    public static void printList(List<?> list) {
        for (Object element : list) {
            System.out.println(element);
        }
    }

    // Method to find the sum of a list of numbers using a wildcard
    public static double sumList(List<? extends Number> list) {
        double sum = 0.0;
        for (Number number : list) {
            sum += number.doubleValue();
        }
        return sum;
    }

    public static void main(String[] args) {
        // Create a list of Integer
        List<Integer> intList = new ArrayList<>();
        intList.add(1);
        intList.add(2);
        intList.add(3);
        
        // Create a list of Double
        List<Double> doubleList = new ArrayList<>();
        doubleList.add(1.1);
        doubleList.add(2.2);
        doubleList.add(3.3);

        // Demonstrate the printList method
        System.out.println("Printing Integer List:");
        printList(intList);
        
        System.out.println("\nPrinting Double List:");
        printList(doubleList);
        
        // Demonstrate the sumList method
        double intSum = sumList(intList);
        double doubleSum = sumList(doubleList);
        
        System.out.println("\nSum of Integer List: " + intSum);
        System.out.println("Sum of Double List: " + doubleSum);
    }
}

/*
Printing Integer List:
1
2
3

Printing Double List:
1.1
2.2
3.3

Sum of Integer List: 6.0
Sum of Double List: 6.6
 */