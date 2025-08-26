# Database Systems (DBS) Labs 1-8

This repository contains the complete source code and SQL scripts for Database Systems (DBS) lab exercises 1 through 8. The labs cover a wide range of topics including C# programming, database design, SQL queries, PL/SQL programming, triggers, procedures, functions, and integration of Oracle database connectivity with C# (Visual Studio).

---

## Lab Overview

### Lab 1: Basic C# Applications
- **Scientific Calculator:** Implements at least 4 different scientific functions (e.g., sin, cos, tan, log).
- **Student Registration Form:** A Windows Forms app with input validation using TextBox, RadioButton, ComboBox, CheckBox, Calendar, Label, Button, and MessageBox.

### Lab 2: Advanced C# Applications
- **Notepad Application:** Utilizes RichTextBox, MenuStrip, FileDialog, ColorDialog, and FontDialog controls.
- **Banking Application:** Multi-form app allowing customer login, password change, displaying account info, and money transfer functionality.

### Lab 3: Database Design and Basic SQL
- Created tables: PERSON, CAR, ACCIDENT, OWNS, PARTICIPATED.
- Inserted sample data into tables.
- Performed basic SQL operations: INSERT, UPDATE, DELETE, ALTER.
- SQL queries involving joins, aggregations, and nested subqueries.

### Lab 4: Complex SQL Queries and Nested Subqueries
- Created student enrollment schema with STUDENT, COURSE, ENROLL, BOOK_ADOPTION, TEXT tables.
- Inserted sample data.
- Executed nested subqueries to retrieve information on courses, departments, students, and books based on various conditions.

### Lab 5: Nested Subqueries (Continued)
- Developed complex nested queries to solve real-world problems like:
  - Courses using multiple textbooks.
  - Departments publishing textbooks by a particular publisher.
  - Students enrolled in courses from multiple departments.
  - Students not enrolled in any courses.
  - Publishers and their book counts.

### Lab 6: PL/SQL Functions and Procedures
- Created stored functions and procedures to:
  - Calculate total accidents in a given year.
  - Show total damage caused by a driver in a year.
  - Display accident info for a specific location.
  - Identify drivers with no accident involvement.
  - Count accidents by car license.

### Lab 7: Triggers and Advanced SQL
- Implemented triggers to:
  - Display driver info upon accident participation.
  - Update total damage in ACCIDENT table on PARTICIPATED insert/delete.
- Wrote queries for:
  - Cars involved in accidents with cumulative damage above a threshold.
  - Cars involved in multiple accidents with total damage.
  - Average damage amount per accident location.

### Lab 8: Oracle Database Connectivity with C# (Visual Studio)
- Established Oracle DB connection from VC# using Oracle Data Access.
- Developed GUI apps to perform CRUD operations on database tables.
- Implemented data navigation (Next, Previous) on records.
- Integrated DataGridView and ComboBox controls populated from DB.
- Executed SQL queries from Labs 3 and 4 through the C# front-end.

---

## Technologies Used

- **Database:** Oracle Database 11g/12c
- **SQL:** DDL, DML, DCL, TCL, PL/SQL
- **Programming Language:** C# (.NET Framework, Windows Forms)
- **IDE:** Visual Studio 2012/2019
- **Oracle Data Provider:** Oracle.DataAccess.Client (ODP.NET)

---

## How to Use

1. **Database Setup:**
   - Execute the SQL scripts from Labs 3 to 7 in your Oracle Database environment to create tables, insert data, and compile functions, procedures, and triggers.
   - Adjust connection details as needed.

2. **C# Frontend:**
   - Open the Visual Studio solution for Lab 8.
   - Configure the connection string with your Oracle DB credentials.
   - Build and run the project to interact with the database through the GUI.

3. **Run Queries:**
   - Use the provided SQL scripts for query exercises.
   - Test stored procedures and triggers in your Oracle environment.