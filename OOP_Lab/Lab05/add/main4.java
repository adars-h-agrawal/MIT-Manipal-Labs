import java.util.Scanner;

class Stack {
    int[] stack = new int[5];
    int top = -1;

    // Push method
    void push(int value) {
        if (top == 4) {
            System.out.println("Stack Overflow!");
        } else {
            stack[++top] = value;
            System.out.println("Pushed " + value);
        }
    }

    // Pop method
    void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow!");
        } else {
            System.out.println("Popped " + stack[top--]);
        }
    }

    // Display stack
    void display() {
        if (top == -1) {
            System.out.println("Stack is empty!");
        } else {
            System.out.println("Stack elements:");
            for (int i = top; i >= 0; i--) {
                System.out.println(stack[i]);
            }
        }
    }

    public static void main4(String[] args) {
        Stack s = new Stack();
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1. Push 2. Pop 3. Display 4. Exit");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("Enter value to push:");
                    int value = sc.nextInt();
                    s.push(value);
                    break;
                case 2:
                    s.pop();
                    break;
                case 3:
                    s.display();
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
