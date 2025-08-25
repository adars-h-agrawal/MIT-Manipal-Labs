import java.util.Scanner;

interface Item {
    void displayDetails();
    double calculateTotalSales();
}

// Hardware class
class Hardware implements Item {
    private String category;
    private String manufacturer;
    private double[] sales; // Sales for the last 3 months

    public Hardware(String category, String manufacturer, double[] sales) {
        this.category = category;
        this.manufacturer = manufacturer;
        this.sales = sales;
    }

    public void displayDetails() {
        System.out.println("Hardware Category: " + category);
        System.out.println("Manufacturer: " + manufacturer);
    }

    public double calculateTotalSales() {
        double total = 0;
        for (double sale : sales) {
            total += sale;
        }
        return total;
    }
}

// Software class
class Software implements Item {
    private String type;
    private String operatingSystem;
    private double[] sales; // Sales for the last 3 months

    public Software(String type, String operatingSystem, double[] sales) {
        this.type = type;
        this.operatingSystem = operatingSystem;
        this.sales = sales;
    }

    public void displayDetails() {
        System.out.println("Software Type: " + type);
        System.out.println("Operating System: " + operatingSystem);
    }

    public double calculateTotalSales() {
        double total = 0;
        for (double sale : sales) {
            total += sale;
        }
        return total;
    }
}

// Main class
public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input for hardware sales
        double[] hardwareSales = new double[3];
        System.out.print("Enter hardware sales for last 3 months:");
        for (int i = 0; i < 3; i++) {
            hardwareSales[i] = sc.nextDouble();
        }
        Hardware hardware = new Hardware("Laptop", "Dell", hardwareSales);

        // Input for software sales
        double[] softwareSales = new double[3];
        System.out.print("Enter software sales for last 3 months:");
        for (int i = 0; i < 3; i++) {
            softwareSales[i] = sc.nextDouble();
        }
        Software software = new Software("Antivirus", "Windows", softwareSales);

        // Display details
        System.out.println("\nHardware Details:");
        hardware.displayDetails();
        System.out.println("Total Hardware Sales: " + hardware.calculateTotalSales());

        System.out.println("\nSoftware Details:");
        software.displayDetails();
        System.out.println("Total Software Sales: " + software.calculateTotalSales());
    }
}