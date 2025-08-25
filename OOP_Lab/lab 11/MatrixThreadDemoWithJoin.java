import java.util.Scanner;

public class MatrixThreadDemoWithJoin {
    public static void main(String[] args) {
        // (Matrix class and MatrixThread class same as above)

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

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("All threads have completed execution.");
    }
}
