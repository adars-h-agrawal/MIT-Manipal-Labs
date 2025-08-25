import java.util.Scanner;
public class non_diagonal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size, sum=0;
        System.out.print("Enter number of rows & coloumns : ");
        size=sc.nextInt(); 
        int [][]matrix = new int[size][size];
        System.out.println("Enter the elements : ");
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                matrix[i][j]=sc.nextInt();
            }
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i!=j && i+j!=size-1){
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
