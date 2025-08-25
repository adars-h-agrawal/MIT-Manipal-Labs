class Student_Detail {
    // Member variables
    String name;
    int id;
    static String college_name = "MIT"; // Since the college name is constant for all students

    // Constructor to initialize name and id
    Student_Detail(String name, int id) {
        this.name = name;
        this.id = id;
    }

    // Method to display student details
    void display_details() {
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("College Name: " + college_name);
    }

    public static void main(String[] args) {
        // Creating student objects
        Student_Detail student1 = new Student_Detail("Alice", 101);
        Student_Detail student2 = new Student_Detail("Bob", 102);

        // Display student details
        student1.display_details();
        System.out.println();
        student2.display_details();
    }
}
