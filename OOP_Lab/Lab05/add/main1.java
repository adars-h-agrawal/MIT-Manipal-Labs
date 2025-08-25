import java.util.Scanner;

class Result {
    int[][] marks = new int[3][3];  // 3 students and 3 subjects
    int[] totalMarks = new int[3];  // Total marks for each student

    // Method to input marks for 3 subjects for each student
    void inputMarks() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            System.out.println("Enter marks for Student " + (i + 1) + " in 3 subjects:");
            for (int j = 0; j < 3; j++) {
                marks[i][j] = sc.nextInt();
            }
        }
    }

    // Method to calculate total marks for each student
    void calculateTotal() {
        for (int i = 0; i < 3; i++) {
            totalMarks[i] = marks[i][0] + marks[i][1] + marks[i][2];
        }
    }

    // Method to find highest marks in each subject and roll number
    void highestInEachSubject() {
        for (int j = 0; j < 3; j++) {
            int highestMarks = 0;
            int rollNo = 0;
            for (int i = 0; i < 3; i++) {
                if (marks[i][j] > highestMarks) {
                    highestMarks = marks[i][j];
                    rollNo = i + 1;
                }
            }
            System.out.println("Highest marks in Subject " + (j + 1) + ": " + highestMarks + " by Roll No: " + rollNo);
        }
    }

    // Method to find the student with the highest total marks
    void highestTotalMarks() {
        int highestTotal = 0;
        int rollNo = 0;
        for (int i = 0; i < 3; i++) {
            if (totalMarks[i] > highestTotal) {
                highestTotal = totalMarks[i];
                rollNo = i + 1;
            }
        }
        System.out.println("Highest total marks: " + highestTotal + " by Roll No: " + rollNo);
    }

    public static void main1(String[] args) {
        Result result = new Result();
        result.inputMarks();
        result.calculateTotal();
        result.highestInEachSubject();
        result.highestTotalMarks();
    }
}
