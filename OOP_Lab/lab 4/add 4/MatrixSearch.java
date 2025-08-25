public class MatrixSearch {
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 2},
            {7, 8, 9}
        };
        int target = 2; // Element to search
        int count = 0;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == target) {
                    count++;
                }
            }
        }

        System.out.println("The element " + target + " occurs " + count + " times.");
    }
}
