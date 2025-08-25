import java.util.Scanner;

// Interface Product with specified methods
interface Product {
    String getProductName();
    String getProductId();
    int getQuantity();
    boolean searchProductName(String name);
    void updateQuantity(int quantity);
}

// User-defined Exception for Out of Stock
class OutOfStockException extends Exception {
    public OutOfStockException(String message) {
        super(message);
    }
}

// GenericProduct class that implements Product interface
class GenericProduct implements Product {
    private String productName;
    private String productId;
    private int quantity;

    public GenericProduct(String productName, String productId, int quantity) {
        this.productName = productName;
        this.productId = productId;
        this.quantity = quantity;
    }

    @Override
    public String getProductName() {
        return productName;
    }

    @Override
    public String getProductId() {
        return productId;
    }

    @Override
    public int getQuantity() {
        return quantity;
    }

    @Override
    public boolean searchProductName(String name) {
        return productName.equalsIgnoreCase(name);
    }

    @Override
    public void updateQuantity(int quantity) {
        this.quantity += quantity;
        System.out.println("Updated quantity for " + productName + " is now: " + this.quantity);
    }
}

// Inventory class implementing Product with processOrder method
class Inventory implements Product {
    private Product[] products;
    private int productCount;

    public Inventory(int size) {
        products = new Product[size];
        productCount = 0;
    }

    // Adding product to inventory
    public void addProduct(Product product) {
        if (productCount < products.length) {
            products[productCount++] = product;
        } else {
            System.out.println("Inventory is full, cannot add more products.");
        }
    }

    // Method to process orders
    public void processOrder(String productId, int orderQuantity) throws OutOfStockException {
        Product product = findProductById(productId);

        if (product != null) {
            if (product.getQuantity() >= orderQuantity) {
                product.updateQuantity(-orderQuantity);
                System.out.println("Order processed. Remaining quantity for " + product.getProductName() + ": " + product.getQuantity());
            } else {
                throw new OutOfStockException("Order cannot be processed. Insufficient stock for " + product.getProductName());
            }
        } else {
            System.out.println("Product with ID " + productId + " not found in inventory.");
        }
    }

    private Product findProductById(String productId) {
        for (Product product : products) {
            if (product != null && product.getProductId().equals(productId)) {
                return product;
            }
        }
        return null;
    }

    @Override
    public String getProductName() {
        return null;  // Not used for Inventory
    }

    @Override
    public String getProductId() {
        return null;  // Not used for Inventory
    }

    @Override
    public int getQuantity() {
        return 0;  // Not used for Inventory
    }

    @Override
    public boolean searchProductName(String name) {
        for (Product product : products) {
            if (product != null && product.searchProductName(name)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public void updateQuantity(int quantity) {
        // Not applicable directly in Inventory class
    }
}

// ElectronicProduct class that extends GenericProduct
class ElectronicProduct extends GenericProduct {
    private String warranty;

    public ElectronicProduct(String productName, String productId, int quantity, String warranty) {
        super(productName, productId, quantity);
        this.warranty = warranty;
    }

    public String getWarranty() {
        return warranty;
    }

    public void setWarranty(String warranty) {
        this.warranty = warranty;
    }

    public void displayProductDetails() {
        System.out.println("Product Name: " + getProductName());
        System.out.println("Product ID: " + getProductId());
        System.out.println("Quantity: " + getQuantity());
        System.out.println("Warranty: " + getWarranty());
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Inventory inventory = new Inventory(10);

        // Adding products to the inventory with user input
        System.out.println("Adding products to inventory...");
        System.out.print("Enter product name: ");
        String productName = scanner.nextLine();
        System.out.print("Enter product ID: ");
        String productId = scanner.nextLine();
        System.out.print("Enter quantity: ");
        int quantity = scanner.nextInt();
        scanner.nextLine();  // Consume newline

        GenericProduct product1 = new GenericProduct(productName, productId, quantity);
        inventory.addProduct(product1);

        System.out.print("Enter electronic product name: ");
        String eProductName = scanner.nextLine();
        System.out.print("Enter electronic product ID: ");
        String eProductId = scanner.nextLine();
        System.out.print("Enter quantity: ");
        int eQuantity = scanner.nextInt();
        scanner.nextLine();  // Consume newline
        System.out.print("Enter warranty period: ");
        String warranty = scanner.nextLine();

        ElectronicProduct product2 = new ElectronicProduct(eProductName, eProductId, eQuantity, warranty);
        inventory.addProduct(product2);

        // Display details of the Electronic Product
        System.out.println("\nElectronic Product Details:");
        product2.displayProductDetails();

        // Process orders and update quantities
        try {
            System.out.print("\nEnter product ID to order: ");
            String orderProductId = scanner.nextLine();
            System.out.print("Enter order quantity: ");
            int orderQuantity = scanner.nextInt();

            inventory.processOrder(orderProductId, orderQuantity);

            System.out.print("\nEnter product ID to order: ");
            scanner.nextLine();  // Consume newline
            orderProductId = scanner.nextLine();
            System.out.print("Enter order quantity: ");
            orderQuantity = scanner.nextInt();

            inventory.processOrder(orderProductId, orderQuantity);

        } catch (OutOfStockException e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Updating quantity manually
        System.out.println("\nUpdating quantity of " + product1.getProductName() + ":");
        System.out.print("Enter additional quantity to add: ");
        int additionalQuantity = scanner.nextInt();
        product1.updateQuantity(additionalQuantity);

        scanner.close();
    }
}
