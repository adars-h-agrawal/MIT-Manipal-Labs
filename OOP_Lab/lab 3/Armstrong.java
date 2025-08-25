import java.util.Scanner;
public class Armstrong {
    public static void main(String[] args) {
        int num, copy, count=0, var, sum=0;
        Scanner input=new Scanner(System.in);
        num=input.nextInt();
        copy=num;
        while(copy>0){
            copy=copy/10;
            count++;
        }
        copy=num;
        for(int i=0;i<count;i++){
            var=copy%10;
            copy=copy/10;
            sum=sum+(int)Math.pow(var, count);
        }
        if(sum==num)
            System.out.println("It is an Armstrong number!");
        else
            System.out.println("It is not an Armstrong number!");
        input.close();
    }
}
