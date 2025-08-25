import java.util.Scanner;

class Matrix {
    private int[][] matrix;
    private int rows, cols;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        matrix = new int[rows][cols];
    }

    public void fillMatrix() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter elements of the matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
    }

    public void displayMatrix() {
        System.out.println("Matrix:");
        for (int[] row : matrix) {
            for (int elem : row) {
                System.out.print(elem + " ");
            }
            System.out.println();
        }
    }

    public void displayTranspose() {
        System.out.println("Transpose:");
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void displayMaxValue() {
        int max = Integer.MIN_VALUE;
        for (int[] row : matrix) {
            for (int elem : row) {
                if (elem > max) max = elem;
            }
        }
        System.out.println("Maximum value in the matrix: " + max);
    }

    public void displayPrincipalDiagonal() {
        System.out.println("Principal Diagonal:");
        for (int i = 0; i < Math.min(rows, cols); i++) {
            System.out.print(matrix[i][i] + " ");
        }
        System.out.println();
    }

    public void displayNonDiagonalElements() {
        System.out.println("Non-Diagonal Elements:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i != j) {
                    System.out.print(matrix[i][j] + " ");
                }
            }
        }
        System.out.println();
    }
}

class MatrixThread extends Thread {
    private final Matrix matrix;
    private final String operation;

    public MatrixThread(Matrix matrix, String operation) {
        this.matrix = matrix;
        this.operation = operation;
    }

    @Override
    public void run() {
        switch (operation) {
            case "display":
                matrix.displayMatrix();
                break;
            case "transpose":
                matrix.displayTranspose();
                break;
            case "max":
                matrix.displayMaxValue();
                break;
            case "diagonal":
                matrix.displayPrincipalDiagonal();
                break;
            case "nonDiagonal":
                matrix.displayNonDiagonalElements();
                break;
        }
    }
}

public class MatrixThreadDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter number of columns: ");
        int cols = scanner.nextInt();
        
        Matrix matrix = new Matrix(rows, cols);
        matrix.fillMatrix();

        MatrixThread t1 = new MatrixThread(matrix, "display");
        MatrixThread t2 = new MatrixThread(matrix, "transpose");
        MatrixThread t3 = new MatrixThread(matrix, "max");
        MatrixThread t4 = new MatrixThread(matrix, "diagonal");
        MatrixThread t5 = new MatrixThread(matrix, "nonDiagonal");

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
    }
}
