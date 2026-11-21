-- ============================================================================
-- LAB 4: Cartesian Product & Relational Joins (university_db)
-- ============================================================================

DROP DATABASE IF EXISTS university_db;
CREATE DATABASE university_db;
USE university_db;

-- Table 1: Instructor (exact records from Lab 4)
CREATE TABLE Instructor (
    Id        INT PRIMARY KEY,
    Name      VARCHAR(50),
    dept_name VARCHAR(30),
    salary    INT
);

INSERT INTO Instructor VALUES
(10101, 'Srinivasan', 'CSE',     65000),
(12121, 'Wu',         'FIN',     90000),
(15151, 'Mozart',     'Music',   40000),
(22222, 'Einstein',   'Physics', 90000),
(32343, 'Said',       'History', 60000),
(33456, 'Gold',       'Physics', 87000),
(45565, 'Katz',       'CSE',     75000),
(58583, 'Cali',       'History', 62000),
(76543, 'Singh',      'FIN',     80000),
(76766, 'Crick',      'Bio',     72000),
(83821, 'Brandt',     'CSE',     92000),
(98345, 'Kim',        'EEE',     80000);

-- Table 2: teaches (companion sample data for testing all joins)
CREATE TABLE teaches (
    Id       INT,
    C_id     VARCHAR(15),
    sec_id   VARCHAR(10),
    semester VARCHAR(15),
    year     INT
);

INSERT INTO teaches VALUES
(10101, 'CS-101',  '1', 'Fall',   2017),
(10101, 'CS-315',  '1', 'Spring', 2018),
(12121, 'FIN-201', '1', 'Spring', 2018),
(15151, 'MU-199',  '1', 'Spring', 2018),
(22222, 'PHY-101', '1', 'Fall',   2017),
(32343, 'HIS-351', '1', 'Spring', 2018),
(45565, 'CS-101',  '1', 'Spring', 2018),
(76766, 'BIO-101', '1', 'Summer', 2017),
(83821, 'CS-190',  '1', 'Spring', 2017),
(98345, 'EE-181',  '1', 'Spring', 2017);


-- ============================================================================
-- LAB 4 QUERIES (Q1 - Q7)
-- ============================================================================

-- Q1. Perform Cartesian Product Operation between Instructor and teaches.
SELECT * FROM Instructor, teaches;

-- Q2. Find those instructors who teach any of the courses.
SELECT Instructor.Name, teaches.C_id
FROM Instructor
INNER JOIN teaches ON Instructor.Id = teaches.Id;

-- Q3. Find instructor names and course id for instructors in CSE department.
SELECT Instructor.Name, teaches.C_id
FROM Instructor
INNER JOIN teaches ON Instructor.Id = teaches.Id
WHERE Instructor.dept_name = 'CSE';

-- Q4. Find the total no. of tuples in "Instructor" relation.
SELECT COUNT(*) AS Total_Instructors FROM Instructor;

-- Q5. Answer Q2 using Natural Join.
SELECT Name, C_id
FROM Instructor NATURAL JOIN teaches;

-- Q6. Perform Left Outer Join.
SELECT * FROM Instructor NATURAL LEFT OUTER JOIN teaches;

-- Q7. Perform Right Outer Join (corrected from Lab 4 sheet typo).
SELECT * FROM Instructor NATURAL RIGHT OUTER JOIN teaches;