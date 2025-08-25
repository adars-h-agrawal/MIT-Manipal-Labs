import java.util.Scanner;
public class Bitwise{
    public static void main(String args[]){
        int x;
        System.out.println("Enter a number: ");
        Scanner a=new Scanner(System.in);
        x=a.nextInt();
        int y=x<<1;
        int z=x>>1;
        System.out.println("Number multiplied by 2 is "+y+" & divided by 2 is "+z+"\n");
    }
}
