import java.util.Scanner;
public class prime {
    public static void main(String[] args) {
        int m,n,count=0;
        Scanner input=new Scanner(System.in);
        System.out.print("Enter m & n :");
        m=input.nextInt();
        n=input.nextInt();
        for(int i=m;i<=n;i++){
            for(int j=2;j<i;j++){
                if(i%j==0)
                    count++;
            }
            if(count==0)
                System.out.print(i+" ");
            count=0;
        }
        input.close();
    }
}
