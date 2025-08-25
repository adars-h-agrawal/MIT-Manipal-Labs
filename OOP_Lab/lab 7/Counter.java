class Counter {
    // Static variable to count the number of objects
    static int count = 0;

    // Constructor to increment the counter when an object is created
    Counter() {
        count++;
    }

    // Method to display the total number of objects created
    static void displayObjectCount() {
        System.out.println("Total number of objects created: " + count);
    }

    public static void main(String[] args) {
        // Creating multiple objects
        Counter obj1 = new Counter();
        Counter obj2 = new Counter();
        Counter obj3 = new Counter();

        // Display the number of objects created
        Counter.displayObjectCount();
    }
}
