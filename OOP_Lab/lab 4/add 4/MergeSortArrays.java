import java.util.Arrays;

public class MergeSortArrays {
    public static void main(String[] args) {
        int[] array1 = {1, 3, 5, 7}; // Example arrays
        int[] array2 = {2, 4, 6, 8};

        // Merge arrays
        int[] mergedArray = new int[array1.length + array2.length];
        System.arraycopy(array1, 0, mergedArray, 0, array1.length);
        System.arraycopy(array2, 0, mergedArray, array1.length, array2.length);

        // Sort the merged array
        Arrays.sort(mergedArray);

        // Print the sorted merged array
        System.out.println("Merged and sorted array:");
        for (int num : mergedArray) {
            System.out.print(num + " ");
        }
    }
}
