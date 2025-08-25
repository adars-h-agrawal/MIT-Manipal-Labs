import java.util.Scanner;
public class multi_mat{
    public static void main(String args[]){
        int i,j,k,r1,c1,r2,c2,sum=0;
        Scanner sc = new Scanner(System.in);

        System.out.print("Matrix A\nEnter the row : ");
        r1=sc.nextInt();
        System.out.print("Enter the column : ");
        c1=sc.nextInt();

        System.out.print("\nMatrix B\nEnter the row : ");
        r2=sc.nextInt();
        System.out.print("Enter the column : ");
        c2=sc.nextInt();
        
        if(c1!=r2){
            System.out.println("No operation possible");
            System.exit(0);
        }
        int a[][] = new int[r1][c1];
        int b[][] = new int[r2][c2];
        
        System.out.println("\nEnter the elements of A :");
        for(i=0;i<r1;i++)
            for(j=0;j<c1;j++)
                a[i][j]=sc.nextInt();

        System.out.println("\nEnter the elements of B :");
        for(i=0;i<r2;i++)
            for(j=0;j<c2;j++)
                b[i][j]=sc.nextInt();

        System.out.print("\nThe Matrix A entered is  : \n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++)            
                System.out.print(a[i][j]+"  ");
            System.out.println();            
        }
        System.out.print("\nThe Matrix B entered is  : \n");
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++)            
                System.out.print(b[i][j]+"  ");
            System.out.println();            
        }

        if(r1==r2 && c1==c2){
            int c[][] = new int[r1][c1];
            System.out.println("\nMatrix Addition\n");
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    c[i][j]=a[i][j]+b[i][j];
                    System.out.print(c[i][j]+"\t");
                }
                System.out.println();
            }
        }
        else
            System.out.println("\nAddition not possible\n");


        System.out.print("\nMatrix Multiplication \n");
        int d[][] = new int[r1][c2];

        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                sum=0;
                for(k=0;k<c1;k++)
                    sum+=a[i][k]*b[k][j];
                d[i][j]=sum;
            }
        }
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++)            
                System.out.print(d[i][j]+"\t");
            System.out.println("\n");            
        }
        sc.close();
    }
}