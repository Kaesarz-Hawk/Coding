-- ============================================================================
-- LAB 1: Database Creation, Table Updates & Basic Filtering (BUBT_DB1)
-- ============================================================================

-- 1. Create Database
DROP DATABASE IF EXISTS BUBT_DB1;
CREATE DATABASE BUBT_DB1;
USE BUBT_DB1;

-- Disable safe update mode so NULL-based updates work smoothly
SET SQL_SAFE_UPDATES = 0;

-- 2. Create Tables & Insert Records

-- Table 1: Student
CREATE TABLE Student (
    Name    VARCHAR(50),
    St_Id   INT PRIMARY KEY,
    NID     INT,
    Intake  INT,
    Section INT,
    CGPA    DECIMAL(3, 2)
);

INSERT INTO Student (Name, St_Id, NID, Intake, Section, CGPA) VALUES
('Ashraful', 1,  102, 44, 1, 3.30),
('Tonny',    2,  101, 44, 1, 3.50),
('Zakir',    33, 103, 35, 2, 3.98),
('Urmi',     6,  104, 35, 1, 3.96),
('Tonny',    23, 105, 44, 1, 3.50);

-- Table 2: Faculty
CREATE TABLE Faculty (
    Name             VARCHAR(60),
    Short_Code       VARCHAR(10),
    Course_Code      VARCHAR(15),
    Conduct_Semester VARCHAR(25)
);

INSERT INTO Faculty (Name, Short_Code, Course_Code, Conduct_Semester) VALUES
('Farha Akhter Munmun', 'FAM',  'CSE 319', 'Summer 2019'),
('Sweety Lima',         'SWL',  'CSE 209', 'Fall 2019-20'),
('Shumi Khatun',        'SKN',  NULL,      'Summer 2019'),
('Nadia Afrin Ritu',    NULL,   'CSE 351', NULL);

-- Table 3: Course
CREATE TABLE Course (
    Course_Title VARCHAR(60),
    Course_Code  VARCHAR(15)
);

INSERT INTO Course (Course_Title, Course_Code) VALUES
('Database Systems',       'CSE 207'),
('Computer Networks',      'CSE 319'),
('Data Communication',     'CSE 209'),
('System Analysis Design', NULL);


-- ============================================================================
-- 3. LAB 1 QUERIES (a - m)
-- ============================================================================

-- 3(a) Update the short code whose short code is NULL.
UPDATE Faculty
SET Short_Code = 'NAR'
WHERE Short_Code IS NULL;

-- 3(b) Update the course code that is NULL.
UPDATE Faculty
SET Course_Code = 'CSE 207'
WHERE Course_Code IS NULL;

UPDATE Course
SET Course_Code = 'CSE 321'
WHERE Course_Code IS NULL;

-- 3(c) Update the conduct semester that is NULL.
UPDATE Faculty
SET Conduct_Semester = 'Spring 2020'
WHERE Conduct_Semester IS NULL;

-- 3(d) Add a new column named "Age" in Student relation.
ALTER TABLE Student
ADD COLUMN Age INT;

-- 3(e) Update the age of each student.
UPDATE Student SET Age = 21 WHERE St_Id = 1;
UPDATE Student SET Age = 22 WHERE St_Id = 2;
UPDATE Student SET Age = 24 WHERE St_Id = 33;
UPDATE Student SET Age = 23 WHERE St_Id = 6;
UPDATE Student SET Age = 22 WHERE St_Id = 23;

-- 3(f) Find the names of all Courses in the Course relation.
SELECT Course_Title FROM Course;

-- 3(g) Find the names of all teachers who conducted in Summer 2019.
SELECT Name FROM Faculty
WHERE Conduct_Semester = 'Summer 2019';

-- 3(h) Find the names of all students whose CGPA is greater than 3.50.
SELECT Name FROM Student
WHERE CGPA > 3.50;

-- 3(i) Add a new column "Offered_Semester" after the column "Course_Title".
ALTER TABLE Course
ADD COLUMN Offered_Semester VARCHAR(25) AFTER Course_Title;

-- 3(j) Find the name and CGPA of each student ordered by CGPA (Ascending).
SELECT Name, CGPA FROM Student
ORDER BY CGPA ASC;

-- 3(k) Find the name of all students whose age > 22 and CGPA > 3.50.
SELECT Name FROM Student
WHERE Age > 22 AND CGPA > 3.50;

-- 3(l) Find the Id of all students from 44 intake or CGPA < 3.40.
SELECT St_Id FROM Student
WHERE Intake = 44 OR CGPA < 3.40;

-- 3(m) Find the Id of all students whose CGPA is 3.30 or 3.50 or 3.96.
SELECT St_Id FROM Student
WHERE CGPA IN (3.30, 3.50, 3.96);