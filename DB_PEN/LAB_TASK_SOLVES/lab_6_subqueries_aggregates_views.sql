-- ============================================================================
-- LAB 6: Subqueries, Top-N, Duplicates, HAVING & Views (college_db)
-- ============================================================================

DROP DATABASE IF EXISTS college_db;
CREATE DATABASE college_db;
USE college_db;

-- Table 1: Department
CREATE TABLE Department (
    Dept_Id   VARCHAR(10) PRIMARY KEY,
    Dept_Name VARCHAR(50) NOT NULL,
    Location  VARCHAR(50)
);

INSERT INTO Department VALUES
('D01', 'CSE',     'Dhaka'),
('D02', 'EEE',     'Dhaka'),
('D03', 'BBA',     'Dhaka'),
('D04', 'English', 'Dhaka');

-- Table 2: Student
CREATE TABLE Student (
    Student_ID   INT PRIMARY KEY,
    Student_Name VARCHAR(50) NOT NULL,
    Gender       VARCHAR(10),
    CGPA         DECIMAL(3, 2),
    Dept_ID      VARCHAR(10),
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_Id)
);

INSERT INTO Student VALUES
(101, 'Rahim',   'Male',   3.75, 'D01'),
(102, 'Karim',   'Male',   3.20, 'D01'),
(103, 'Nusrat',  'Female', 3.90, 'D02'),
(104, 'Sumaiya', 'Female', 3.60, 'D01'),
(105, 'Imran',   'Male',   3.45, 'D03'),
(106, 'Mim',     'Female', 3.85, 'D02');


-- ============================================================================
-- LAB 6 QUERIES (Q1 - Q10)
-- ============================================================================

-- Q1. Find the department having the highest number of students.
SELECT d.Dept_Id, d.Dept_Name, COUNT(s.Student_ID) AS Total_Students
FROM Department d
INNER JOIN Student s ON d.Dept_Id = s.Dept_ID
GROUP BY d.Dept_Id, d.Dept_Name
ORDER BY Total_Students DESC
LIMIT 1;

-- Q2. Display the second-highest CGPA among students.
-- Method 1 (Subquery - safest for ties):
SELECT MAX(CGPA) AS Second_Highest_CGPA
FROM Student
WHERE CGPA < (SELECT MAX(CGPA) FROM Student);

-- Method 2 (LIMIT + OFFSET):
SELECT DISTINCT CGPA AS Second_Highest_CGPA
FROM Student
ORDER BY CGPA DESC
LIMIT 1 OFFSET 1;

-- Q3. Find students who have the same CGPA.
SELECT * FROM Student
WHERE CGPA IN (
    SELECT CGPA FROM Student
    GROUP BY CGPA
    HAVING COUNT(*) > 1
);

-- Q4. Calculate the average CGPA for each department.
SELECT d.Dept_Name, AVG(s.CGPA) AS Avg_CGPA
FROM Department d
INNER JOIN Student s ON d.Dept_Id = s.Dept_ID
GROUP BY d.Dept_Id, d.Dept_Name;

-- Q5. Find the total number of students whose CGPA is greater than 3.50.
SELECT COUNT(*) AS High_CGPA_Students
FROM Student
WHERE CGPA > 3.50;

-- Q6. Display students whose CGPA is greater than the CGPA of student 102.
SELECT * FROM Student
WHERE CGPA > (SELECT CGPA FROM Student WHERE Student_ID = 102);

-- Q7. Create a view named Student_View displaying student ID, name, and CGPA.
CREATE OR REPLACE VIEW Student_View AS
SELECT Student_ID, Student_Name, CGPA
FROM Student;

-- Q8. Retrieve records from a view using SELECT.
SELECT * FROM Student_View;

-- Q9. Create a view named CSE_Students displaying only CSE students.
CREATE OR REPLACE VIEW CSE_Students AS
SELECT s.Student_ID, s.Student_Name, s.Gender, s.CGPA, d.Dept_Name
FROM Student s
INNER JOIN Department d ON s.Dept_ID = d.Dept_Id
WHERE d.Dept_Name = 'CSE';

-- Verify Q9 view:
SELECT * FROM CSE_Students;

-- Q10. Display departments having more than one student using HAVING.
SELECT d.Dept_Id, d.Dept_Name, COUNT(s.Student_ID) AS Student_Count
FROM Department d
INNER JOIN Student s ON d.Dept_Id = s.Dept_ID
GROUP BY d.Dept_Id, d.Dept_Name
HAVING COUNT(s.Student_ID) > 1;