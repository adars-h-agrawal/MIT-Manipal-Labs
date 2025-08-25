import java.util.Scanner;

public class Calculator {
  public static void main(String[] args) {

    char operator;
    Double number1, number2, result;
    Scanner input = new Scanner(System.in);
    char ch = 'y';

    do{
        System.out.print("Enter first number, operator, second number : ");
        number1 = input.nextDouble();
        operator = input.next().charAt(0);
        number2 = input.nextDouble();
        switch (operator) {
            case '+':
            result = number1 + number2;
            System.out.println("Answer =  " + result);
            break;
            
            case '-':
            result = number1 - number2;
            System.out.println("Answer =  " + result);
            break;

            case '*':
            result = number1 * number2;
            System.out.println("Answer =  " + result);
            break;

            case '/':
            result = number1 / number2;
            System.out.println("Answer =  " + result);
            break;

            default:
            System.out.println("Invalid operator!");
            break;
        }
        System.out.print("Do another (y/n)?\t");
        ch=input.next().charAt(0);
        
    }while(ch=='y');
    input.close();
  }
}
