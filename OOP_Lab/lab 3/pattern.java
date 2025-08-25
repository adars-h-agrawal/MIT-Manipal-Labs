import java.util.Scanner;
public class pattern {
    public static void main(String[] args) {
        for(int i=1;i<6;i++){
            for(int j=1;j<=i;j++){
                System.out.print(i+" ");
            }
            System.out.println();
        }
        int a[]={1,2,3,4,5};
        for(int x:a){
            int b[]=new int[x];
            for(int y:b)
                System.out.print(x+" ");
            System.out.println();
        }
    }
}
