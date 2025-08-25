public class AutoboxingUnboxingDemo {
    public static void main(String[] args) {
        // Autoboxing: converting primitives to wrapper objects
        Integer intObj = 100;         // int to Integer
        Double doubleObj = 10.5;      // double to Double
        Character charObj = 'A';      // char to Character
        Boolean boolObj = true;       // boolean to Boolean

        // Unboxing: converting wrapper objects to primitives
        int intValue = intObj;        // Integer to int
        double doubleValue = doubleObj; // Double to double
        char charValue = charObj;     // Character to char
        boolean boolValue = boolObj;  // Boolean to boolean

        // Display values to demonstrate autoboxing and unboxing
        System.out.println("Autoboxed Integer object: " + intObj);
        System.out.println("Autoboxed Double object: " + doubleObj);
        System.out.println("Autoboxed Character object: " + charObj);
        System.out.println("Autoboxed Boolean object: " + boolObj);

        System.out.println("\nUnboxed int value: " + intValue);
        System.out.println("Unboxed double value: " + doubleValue);
        System.out.println("Unboxed char value: " + charValue);
        System.out.println("Unboxed boolean value: " + boolValue);
    }
}
