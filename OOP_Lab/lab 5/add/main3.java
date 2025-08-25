class Swap {
    
    // Swap using call by value
    void swapByValue(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
        System.out.println("After swapping (by value): a = " + a + ", b = " + b);
    }

    // Swap using call by reference (using an array)
    void swapByReference(int[] arr) {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
        System.out.println("After swapping (by reference): arr[0] = " + arr[0] + ", arr[1] = " + arr[1]);
    }

    public static void main3(String[] args) {
        Swap swapObj = new Swap();
        
        // Call by value
        int x = 5, y = 10;
        System.out.println("Before swapping (by value): a = " + x + ", b = " + y);
        swapObj.swapByValue(x, y);
        
        // Call by reference
        int[] arr = {5, 10};
        System.out.println("Before swapping (by reference): arr[0] = " + arr[0] + ", arr[1] = " + arr[1]);
        swapObj.swapByReference(arr);
    }
}
