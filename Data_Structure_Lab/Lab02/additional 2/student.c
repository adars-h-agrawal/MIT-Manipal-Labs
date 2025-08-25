#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to hold student data
struct Student {
    char name[50];
    int rollNo;
    char grade[5];
    char branch[20];
};

// Function to write student records into a text file
void writeRecordsToFile(struct Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %s %s\n", students[i].name, students[i].rollNo, students[i].grade, students[i].branch);
    }

    fclose(file);
}

// Function to read records from the text file and store them branch-wise
void readRecordsAndStoreBranchWise() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    struct Student student;
    char branchFileName[30];
    FILE *branchFile;

    while (fscanf(file, "%s %d %s %s", student.name, &student.rollNo, student.grade, student.branch) != EOF) {
        // Create a branch-specific file
        snprintf(branchFileName, sizeof(branchFileName), "%s.txt", student.branch);
        branchFile = fopen(branchFileName, "a");
        if (branchFile == NULL) {
            printf("Error opening branch file!\n");
            exit(1);
        }

        // Write the student record to the branch-specific file
        fprintf(branchFile, "%s %d %s %s\n", student.name, student.rollNo, student.grade, student.branch);

        fclose(branchFile);
    }

    fclose(file);
}

int main() {
    struct Student students[MAX];
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Input student records
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Grade: ");
        scanf("%s", students[i].grade);
        printf("Branch: ");
        scanf("%s", students[i].branch);
    }

    // Write records to the text file
    writeRecordsToFile(students, n);

    // Read records and store them branch-wise
    readRecordsAndStoreBranchWise();

    printf("Student records have been stored branch-wise in separate files.\n");

    return 0;
}
