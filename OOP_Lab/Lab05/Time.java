import java.util.Scanner;
 
class Time {
    private int hours;
    private int minutes;
    private int seconds;

    // Constructor to initialize time to zero
    public Time() {
        this.hours = 0;
        this.minutes = 0;
        this.seconds = 0;
    }

    // Constructor to initialize time to fixed values
    public Time(int hours, int minutes, int seconds) {
        this.hours = hours;
        this.minutes = minutes;
        this.seconds = seconds;
    }

    // Method to display time in hh:mm:ss format
    public void displayTime() {
        System.out.printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    }

    // Method to add two Time objects
    public static Time addTimes(Time t1, Time t2) {
        int sec = t1.seconds + t2.seconds;
        int min = t1.minutes + t2.minutes + sec / 60;
        int hr = t1.hours + t2.hours + min / 60;

        return new Time(hr % 24, min % 60, sec % 60);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // First time input
        System.out.print("Enter the first time (hours minutes seconds): ");
        int h1 = scanner.nextInt();
        int m1 = scanner.nextInt();
        int s1 = scanner.nextInt();
        Time time1 = new Time(h1, m1, s1);

        // Second time input
        System.out.print("Enter the second time (hours minutes seconds): ");
        int h2 = scanner.nextInt();
        int m2 = scanner.nextInt();
        int s2 = scanner.nextInt();
        Time time2 = new Time(h2, m2, s2);

        time1.displayTime();
        time2.displayTime();

        Time result = Time.addTimes(time1, time2);
        System.out.print("Sum of time: ");
        result.displayTime();

        scanner.close();
    }
}
