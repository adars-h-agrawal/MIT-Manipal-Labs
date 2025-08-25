import java.util.Scanner;

class MyRunnable implements Runnable {
    @Override
    public void run() {
        System.out.println("Thread created using Runnable Interface.");
    }
}

class MyThread extends Thread {
    @Override
    public void run() {
        System.out.println("Thread created by inheriting Thread class.");
    }
}

public class MenuDrivenThreads {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Create Thread using Runnable");
            System.out.println("2. Create Thread by inheriting Thread class");
            System.out.println("3. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    Thread runnableThread = new Thread(new MyRunnable());
                    runnableThread.start();
                    break;
                case 2:
                    MyThread threadClass = new MyThread();
                    threadClass.start();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
}