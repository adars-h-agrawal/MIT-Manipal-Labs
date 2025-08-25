import java.util.Scanner;
public class diagonal_sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int row,col, sum=0;
        System.out.print("Enter number of rows & colums : ");
        row=sc.nextInt(); col=sc.nextInt();
        int [][]matrix = new int[row][col];
        System.out.println("Enter the elements : ");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==j){
                    System.out.print(matrix[i][j]+" ");
                    sum+=matrix[i][j];
                }
            }
        }
        System.out.println();
        System.out.println(sum);
        sc.close();
    }
}