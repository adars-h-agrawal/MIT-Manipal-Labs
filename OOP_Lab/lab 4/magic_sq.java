import java.util.Scanner;
public class magic_sq{
    public static void main(String args[]){
        int i,j,size,ds1=0,ds2=0,s1,s2;
        boolean flag=true;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the size of the matrix : ");
        size=sc.nextInt();
        int a[][] = new int[size][size];
        System.out.println("Enter the elements : ");
        for(i=0;i<size;i++){
            for(j=0;j<size;j++)
                a[i][j]=sc.nextInt();
            ds1=ds1+a[i][i];
            ds2=ds2+a[i][size-1-i];
        }
        System.out.print("\nThe matrix entered is  : \n");
        for(i=0;i<size;i++){
            for(j=0;j<size;j++)            
                System.out.print(a[i][j]+"\t");
            System.out.println();            
        }

        for(i=0;i<size;i++){
            s1=0; s2=0;
            for(j=0;j<size;j++){
                s1=s1+a[i][j];
                s2=s2+a[j][i];
            }
            if(s1!=s2 || s1!=ds1)
                flag=false;
        }
        if(flag)
            System.out.println("Magic Square");
        else    
            System.out.println("Not a magic square");
    }
}