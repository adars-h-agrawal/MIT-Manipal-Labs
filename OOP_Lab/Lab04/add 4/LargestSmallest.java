public class LargestSmallest {
    public static void main(String[] args) {
        int[] array = {34, 7, 23, 32, 5, 62, 15}; // Example array
        int largest = array[0];
        int smallest = array[0];

        for (int num : array) {
            if (num > largest) {
                largest = num;
            }
            if (num < smallest) {
                smallest = num;
            }
        }

        System.out.println("Largest element: " + largest);
        System.out.println("Smallest element: " + smallest);
    }
}
