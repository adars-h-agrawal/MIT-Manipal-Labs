import java.util.Scanner;
public class Search {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter number of elements :");
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        System.out.print("Enter search element : ");
        int x=sc.nextInt();
        System.out.print("The value is found at locations:\t");
        for(int i=0;i<n;i++){
            if(arr[i]==x)
                System.out.print("a["+i+"]"+" ");
        }
        sc.close();
    }
}
