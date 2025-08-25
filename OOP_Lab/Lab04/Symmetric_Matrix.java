import java.util.Scanner;
public class Symmetric_Matrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size;
        System.out.print("Enter number of rows & colums : ");
        size=sc.nextInt(); 
        int [][]matrix = new int[size][size];
        System.out.println("Enter the elements : ");
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        int [][]tmatrix = new int[size][size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                tmatrix[i][j]=matrix[j][i];
            }
        }
        int flag=1;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(tmatrix[i][j]!=matrix[i][j]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)
            System.out.println("Symmetric!");
        else
            System.out.println("Not Symmetric!");
        sc.close();
    }
}
