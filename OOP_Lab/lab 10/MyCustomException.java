// Custom Exception Class
class MyCustomException extends Exception {
    public MyCustomException(String message) {
        super(message);
    }
}

// Main Class to Test the Custom Exception
public class CustomExceptionDemo {
    public static void main(String[] args) {
        try {
            // Simulating a condition that causes an exception
            boolean errorCondition = true; // Change this to false to avoid the exception
            
            if (errorCondition) {
                throw new MyCustomException("This is a custom error message!");
            }
        } catch (MyCustomException e) {
            System.out.println("Caught Exception: " + e.getMessage());
        }
    }
}