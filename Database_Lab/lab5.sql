-- LAB 5: NESTED SUBQUERIES - STUDENT COURSE ENROLLMENT DATABASE

-- ====================================
-- i) CREATE TABLES
-- ====================================

CREATE TABLE STUDENT (
    regno VARCHAR(20) PRIMARY KEY,
    name VARCHAR(50),
    major VARCHAR(20),
    bdate DATE
);

CREATE TABLE COURSE (
    course_id INT PRIMARY KEY,
    cname VARCHAR(30),
    dept VARCHAR(30)
);

CREATE TABLE ENROLL (
    regno VARCHAR(20),
    course_id INT,
    sem INT,
    book_isbn INT,
    PRIMARY KEY (regno, course_id),
    FOREIGN KEY (regno) REFERENCES STUDENT(regno),
    FOREIGN KEY (course_id) REFERENCES COURSE(course_id),
    FOREIGN KEY (book_isbn) REFERENCES TEXT(book_isbn)
);

CREATE TABLE BOOK_ADOPTION (
    course_id INT,
    sem INT,
    book_isbn INT,
    PRIMARY KEY (course_id, sem, book_isbn),
    FOREIGN KEY (course_id) REFERENCES COURSE(course_id),
    FOREIGN KEY (book_isbn) REFERENCES TEXT(book_isbn)
);

CREATE TABLE TEXT (
    book_isbn INT PRIMARY KEY,
    book_title VARCHAR(50),
    publisher VARCHAR(50),
    author VARCHAR(50)
);

-- ====================================
-- ii) INSERT VALUES
-- ====================================

-- STUDENTS
INSERT INTO STUDENT VALUES 
('23091', 'devansh', 'hindi', TO_DATE('2000-10-05','YYYY-MM-DD')),
('23092', 'vedant', 'maths', TO_DATE('2002-09-03','YYYY-MM-DD')),
('23093', 'chirag', 'maths', TO_DATE('2005-12-25','YYYY-MM-DD')),
('23094', 'shaket', 'science', TO_DATE('2006-04-16','YYYY-MM-DD')),
('23095', 'shubham', 'english', TO_DATE('2006-01-18','YYYY-MM-DD'));

-- COURSES
INSERT INTO COURSE VALUES 
(231, 'hindi', 'HINDI'),
(232, 'maths', 'MATHS'),
(233, 'dsa', 'ICT'),
(234, 'oop', 'ICT'),
(235, 'dbs', 'ICT');

-- TEXT BOOKS
INSERT INTO TEXT VALUES 
(34000, 'dsa basics', 'xyz', 'abc'),
(34010, 'dsa advanced', 'xyz', 'abc'),
(36700, 'dbs basics', 'xyz', 'def'),
(1200, 'hindi basics', 'ijk', 'mnop'),
(487, 'maths grand', 'ijk', 'mnop');

-- ENROLLMENTS
INSERT INTO ENROLL VALUES 
('23091', 233, 3, 34000),
('23092', 233, 3, 34010),
('23093', 235, 4, 36700),
('23094', 231, 1, 1200),
('23095', 232, 2, 487);

-- BOOK ADOPTION
INSERT INTO BOOK_ADOPTION VALUES 
(233, 3, 34000),
(233, 3, 34010),
(235, 4, 36700),
(231, 1, 1200),
(232, 2, 487);

-- ====================================
-- iii) NESTED SUBQUERY QUERIES
-- ====================================

-- a. List the courses which use more than 1 text book
SELECT course_id 
FROM BOOK_ADOPTION
GROUP BY course_id
HAVING COUNT(book_isbn) > 1;

-- b. List departments whose all course textbooks are published by a particular publisher (e.g., 'xyz')
SELECT DISTINCT dept
FROM COURSE
WHERE dept NOT IN (
    SELECT DISTINCT c.dept
    FROM COURSE c
    JOIN BOOK_ADOPTION b ON c.course_id = b.course_id
    JOIN TEXT t ON b.book_isbn = t.book_isbn
    WHERE t.publisher != 'xyz'
);

-- c. Find students who have enrolled for courses from more than one department
SELECT regno
FROM ENROLL e
JOIN COURSE c ON e.course_id = c.course_id
GROUP BY regno
HAVING COUNT(DISTINCT c.dept) > 1;

-- d. List students who are not enrolled
SELECT * 
FROM STUDENT 
WHERE regno NOT IN (SELECT DISTINCT regno FROM ENROLL);

-- e. List departments that adopt all books from a particular publisher (e.g., 'xyz')
SELECT DISTINCT dept
FROM COURSE c
WHERE NOT EXISTS (
    SELECT * FROM BOOK_ADOPTION ba
    JOIN TEXT t ON ba.book_isbn = t.book_isbn
    WHERE c.course_id = ba.course_id AND t.publisher != 'xyz'
);

-- f. List the books which are adopted by the course as well as enrolled by the student
SELECT DISTINCT t.book_title
FROM TEXT t
WHERE t.book_isbn IN (
    SELECT book_isbn FROM ENROLL
    INTERSECT
    SELECT book_isbn FROM BOOK_ADOPTION
);

-- g. List the courses which have adopted at least two books from a specific publisher (e.g., 'xyz')
SELECT course_id
FROM BOOK_ADOPTION ba
JOIN TEXT t ON ba.book_isbn = t.book_isbn
WHERE t.publisher = 'xyz'
GROUP BY course_id
HAVING COUNT(DISTINCT t.book_isbn) >= 2;

-- h. Identify the students who are enrolled for the maximum number of books
SELECT regno
FROM ENROLL
GROUP BY regno
HAVING COUNT(book_isbn) = (
    SELECT MAX(book_count)
    FROM (
        SELECT COUNT(book_isbn) AS book_count
        FROM ENROLL
        GROUP BY regno
    )
);

-- i. List publishers along with the number of books published by them
SELECT publisher, COUNT(*) AS num_books
FROM TEXT
GROUP BY publisher;

-- j. List students who enrolled for all the books adopted by their course
SELECT DISTINCT s.regno
FROM STUDENT s
WHERE NOT EXISTS (
    SELECT *
    FROM BOOK_ADOPTION ba
    WHERE ba.course_id IN (
        SELECT e.course_id
        FROM ENROLL e
        WHERE e.regno = s.regno
    )
    AND NOT EXISTS (
        SELECT *
        FROM ENROLL e2
        WHERE e2.regno = s.regno AND e2.book_isbn = ba.book_isbn
    )
);