import java.util.Scanner;

public class MatrixTraceNorm {
    // Method to calculate the trace of a square matrix
    public static int calculateTrace(int[][] matrix) {
        int trace = 0;
        for (int i = 0; i < matrix.length; i++) {
            trace += matrix[i][i];
        }
        return trace;
    }

    // Method to calculate the norm of a square matrix
    public static double calculateNorm(int[][] matrix) {
        double sumOfSquares = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                sumOfSquares += Math.pow(matrix[i][j], 2);
            }
        }
        return Math.sqrt(sumOfSquares);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the square matrix: ");
        int size = scanner.nextInt();
        int[][] matrix = new int[size][size];

        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        scanner.close();

        int trace = calculateTrace(matrix);
        double norm = calculateNorm(matrix);

        System.out.println("Trace of the matrix: " + trace);
        System.out.println("Norm of the matrix: " + norm);
    }
}
