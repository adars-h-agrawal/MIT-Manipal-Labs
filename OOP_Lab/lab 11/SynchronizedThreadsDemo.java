import java.util.Scanner;

class Counter {
    private int count = 0;

    // Synchronized method
    public synchronized void incrementSynchronizedMethod() {
        count++;
        System.out.println("Synchronized Method - Count: " + count);
    }

    // Synchronized block
    public void incrementSynchronizedBlock() {
        synchronized (this) {
            count++;
            System.out.println("Synchronized Block - Count: " + count);
        }
    }

    // Method to get the count
    public int getCount() {
        return count;
    }
}

class SyncMethodThread extends Thread {
    private final Counter counter;
    private final int increments;

    public SyncMethodThread(Counter counter, int increments) {
        this.counter = counter;
        this.increments = increments;
    }

    @Override
    public void run() {
        for (int i = 0; i < increments; i++) {
            counter.incrementSynchronizedMethod();
        }
    }
}

class SyncBlockThread extends Thread {
    private final Counter counter;
    private final int increments;

    public SyncBlockThread(Counter counter, int increments) {
        this.counter = counter;
        this.increments = increments;
    }

    @Override
    public void run() {
        for (int i = 0; i < increments; i++) {
            counter.incrementSynchronizedBlock();
        }
    }
}

public class SynchronizedThreadsDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of increments for each thread: ");
        int increments = scanner.nextInt();

        Counter counter = new Counter();

        SyncMethodThread thread1 = new SyncMethodThread(counter, increments);
        SyncBlockThread thread2 = new SyncBlockThread(counter, increments);

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Final Count: " + counter.getCount());
        scanner.close();
    }
}


/*Enter the number of increments for each thread: 5
Synchronized Method - Count: 1
Synchronized Block - Count: 1
Synchronized Method - Count: 2
Synchronized Block - Count: 2
Synchronized Method - Count: 3
Synchronized Block - Count: 3
Synchronized Method - Count: 4
Synchronized Block - Count: 4
Synchronized Method - Count: 5
Synchronized Block - Count: 5
Final Count: 10
 */
