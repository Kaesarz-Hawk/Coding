-- ============================================================================
-- 100% CRACKABLE DBMS LAB EXAM PATTERN BANK + BANGLA VIVA NOTES
-- Tip: Press Ctrl+F in VS Code and search "PATTERN 1" .. "PATTERN 10"
-- ============================================================================

DROP DATABASE IF EXISTS exam_master_db;
CREATE DATABASE exam_master_db;
USE exam_master_db;
SET SQL_SAFE_UPDATES = 0;

-- ============================================================================
-- MASTER PRACTICE SCHEMA (Run this block once to test all patterns below)
-- ============================================================================

CREATE TABLE Department (
    Dept_Id   VARCHAR(10) PRIMARY KEY,
    Dept_Name VARCHAR(50) NOT NULL,
    Location  VARCHAR(50)
);

CREATE TABLE Student (
    Student_ID   INT PRIMARY KEY,
    Student_Name VARCHAR(60) NOT NULL,
    Email        VARCHAR(100) UNIQUE,
    CGPA         DECIMAL(3, 2) CHECK (CGPA > 0.00 AND CGPA <= 4.00),
    Joining_Date DATE DEFAULT (CURRENT_DATE),
    Dept_ID      VARCHAR(10),
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_Id)
);

CREATE TABLE Loan (
    loan_number VARCHAR(15) PRIMARY KEY,
    branch_name VARCHAR(30),
    amount      INT
);

CREATE TABLE Borrower (
    customer_name VARCHAR(30),
    loan_number   VARCHAR(15)
);

CREATE TABLE Depositor (
    customer_name  VARCHAR(30),
    account_number VARCHAR(15)
);

INSERT INTO Department VALUES
('D01', 'CSE',     'Dhaka'),
('D02', 'EEE',     'Dhaka'),
('D03', 'BBA',     'Chittagong'),
('D04', 'English', 'Dhaka');

INSERT INTO Student VALUES
(101, 'Rahim',   'rahim@mail.com',   3.75, '2025-01-10', 'D01'),
(102, 'Karim',   'karim@mail.com',   3.20, '2025-02-15', 'D01'),
(103, 'Nusrat',  'nusrat@mail.com',  3.90, '2025-03-05', 'D02'),
(104, 'Sumaiya', 'sumaiya@mail.com', 3.75, '2025-04-20', 'D01'),
(105, 'Imran',   'imran@mail.com',   3.45, '2024-11-12', 'D03'),
(106, 'Mim',     'mim@mail.com',     3.85, '2025-05-01', 'D02');

INSERT INTO Loan VALUES
('L-14', 'Downtown',   1500),
('L-15', 'Perryridge', 1500),
('L-16', 'Perryridge', 1300),
('L-93', 'Mianus',     500);

INSERT INTO Borrower VALUES
('Johnson', 'L-14'),
('Hayes',   'L-15'),
('Adams',   'L-16'),
('Curry',   'L-93');

INSERT INTO Depositor VALUES
('Johnson', 'A-101'),
('Hayes',   'A-102'),
('Jones',   'A-217'),
('Lindsay', 'A-222');


-- ============================================================================
-- PATTERN 1: TABLE CREATION & CONSTRAINTS
-- VIVA (Bangla): Parent table age create korte hoy. PK unique+not null,
-- CHECK condition verify kore, DEFAULT (CURRENT_DATE) ajker tarikh bosay.
-- ============================================================================
/*
CREATE TABLE ChildTable (
    id           INT PRIMARY KEY,
    name         VARCHAR(100) NOT NULL,
    email        VARCHAR(100) UNIQUE,
    salary       DECIMAL(10, 2) CHECK (salary > 10000),
    joining_date DATE DEFAULT (CURRENT_DATE),
    parent_id    VARCHAR(10),
    FOREIGN KEY (parent_id) REFERENCES ParentTable(parent_id)
);
*/


-- ============================================================================
-- PATTERN 2: ALTER TABLE (ADD, AFTER, CHANGE COLUMN)
-- VIVA (Bangla): Table structure bodlate ALTER TABLE. Nirdishto column-er
-- por bosate AFTER ar column name+type eksathe bodlate CHANGE COLUMN.
-- ============================================================================
ALTER TABLE Student ADD COLUMN Age INT AFTER Student_Name;
ALTER TABLE Department CHANGE COLUMN Location City VARCHAR(50);


-- ============================================================================
-- PATTERN 3: SAFE UPDATES (IS NULL) & DELETES (BETWEEN)
-- VIVA (Bangla): NULL check korte oboshoy IS NULL dite hoy (= NULL kaj kore na).
-- BETWEEN 1300 AND 1500 duti pranto-shoho range delete kore.
-- ============================================================================
UPDATE Student SET Dept_ID = 'D01' WHERE Dept_ID IS NULL;
-- DELETE FROM Loan WHERE amount BETWEEN 1300 AND 1500;


-- ============================================================================
-- PATTERN 4: FILTERING, WILDCARDS (LIKE) & DATE QUERIES
-- VIVA (Bangla): % = 0 ba tar beshi char, _ = thik 1 ta char.
-- '_%a%_' mane 'a'-er age o pore antoto 1 ta char thaktei hobe.
-- ============================================================================
SELECT Student_Name FROM Student WHERE Student_Name LIKE 'R%';      -- Starts with R
SELECT Student_Name FROM Student WHERE Student_Name LIKE '%m';      -- Ends with m
SELECT Student_Name FROM Student WHERE Student_Name LIKE '_a%';     -- 2nd char is 'a'
SELECT Student_Name FROM Student WHERE Student_Name LIKE '_%a%_';   -- 'a' except 1st & last

SELECT Student_Name, CGPA FROM Student
WHERE Joining_Date > '2025-01-01'
ORDER BY CGPA DESC;

SELECT * FROM Department WHERE City NOT IN ('Dhaka', 'Sylhet');


-- ============================================================================
-- PATTERN 5: ARITHMETIC, ALIASES (AS) & STRING FUNCTIONS
-- VIVA (Bangla): 6% increase = * 1.06, 5% = * 1.05. AS diye output column
-- rename kora hoy (original table change hoy na). SUBSTR(col, 1, 3) 1st 3 char dey.
-- ============================================================================
SELECT loan_number, amount * 1.06 AS New_Amount
FROM Loan
WHERE amount > 1000;

SELECT Student_Name,
       LENGTH(Student_Name)       AS Name_Length,
       SUBSTR(Student_Name, 1, 3) AS First_Three
FROM Student;


-- ============================================================================
-- PATTERN 6: AGGREGATES, GROUP BY & HAVING
-- VIVA (Bangla): "Each dept/branch" thaklei GROUP BY. Aggregate function
-- (SUM/AVG/COUNT) condition kokhono WHERE-e boshe na, HAVING-e boshe.
-- ============================================================================
SELECT Dept_ID, AVG(CGPA) AS Avg_CGPA
FROM Student
GROUP BY Dept_ID;

SELECT branch_name, SUM(amount) AS Total_Loan
FROM Loan
GROUP BY branch_name
HAVING SUM(amount) > 1200;

SELECT Dept_ID, COUNT(Student_ID) AS Total_Students
FROM Student
GROUP BY Dept_ID
HAVING COUNT(Student_ID) > 1;


-- ============================================================================
-- PATTERN 7: JOINS (INNER, LEFT, RIGHT, NATURAL, CARTESIAN)
-- VIVA (Bangla): INNER = shudhu match. LEFT = bam table-er shob + NULL.
-- RIGHT = dan table-er shob + NULL. NATURAL = same column name-e auto join.
-- ============================================================================
SELECT s.Student_Name, d.Dept_Name
FROM Student s
INNER JOIN Department d ON s.Dept_ID = d.Dept_Id;

SELECT d.Dept_Name, s.Student_Name
FROM Department d
LEFT OUTER JOIN Student s ON d.Dept_Id = s.Dept_ID;

SELECT d.Dept_Name, s.Student_Name
FROM Department d
RIGHT OUTER JOIN Student s ON d.Dept_Id = s.Dept_ID;

SELECT * FROM Department NATURAL JOIN Student;
SELECT * FROM Department, Student; -- Cartesian Product (m x n rows)


-- ============================================================================
-- PATTERN 8: SET OPERATIONS (UNION, BOTH/IN, ONLY A NOT B)
-- VIVA (Bangla): Either or both = UNION (duplicate bad dey).
-- Both = IN subquery / INTERSECT. Only A not B = NOT IN.
-- ============================================================================
-- Either loan OR account OR both
(SELECT customer_name FROM Borrower)
UNION
(SELECT customer_name FROM Depositor);

-- Both loan AND account (works on ALL MySQL versions)
SELECT DISTINCT customer_name FROM Borrower
WHERE customer_name IN (SELECT customer_name FROM Depositor);

-- Only account, NOT any loan
SELECT DISTINCT customer_name FROM Depositor
WHERE customer_name NOT IN (SELECT customer_name FROM Borrower);


-- ============================================================================
-- PATTERN 9: TRICKY SUBQUERIES & RANKING (LAB 6 EXAM SPECIALS)
-- VIVA (Bangla): Subquery age bhetorer query run kore, tarpor result ta
-- bairer query-te pass kore. 2nd highest-e MAX < (SELECT MAX) tie handle kore.
-- ============================================================================
-- 9(a) Department with highest number of students
SELECT d.Dept_Name, COUNT(s.Student_ID) AS Total
FROM Department d INNER JOIN Student s ON d.Dept_Id = s.Dept_ID
GROUP BY d.Dept_Id, d.Dept_Name
ORDER BY Total DESC
LIMIT 1;

-- 9(b) Second-highest CGPA
SELECT MAX(CGPA) AS Second_Highest
FROM Student
WHERE CGPA < (SELECT MAX(CGPA) FROM Student);

-- 9(c) Students having the exact same CGPA (duplicates)
SELECT * FROM Student
WHERE CGPA IN (
    SELECT CGPA FROM Student
    GROUP BY CGPA
    HAVING COUNT(*) > 1
);

-- 9(d) Students with CGPA greater than Student 102
SELECT * FROM Student
WHERE CGPA > (SELECT CGPA FROM Student WHERE Student_ID = 102);


-- ============================================================================
-- PATTERN 10: VIEWS (CREATE & SELECT)
-- VIVA (Bangla): VIEW holo virtual table; kono real data store kore na,
-- shudhu SELECT query save rakhe ar run korle live data dekhay.
-- ============================================================================
CREATE OR REPLACE VIEW CSE_Students AS
SELECT s.Student_ID, s.Student_Name, s.CGPA, d.Dept_Name
FROM Student s
INNER JOIN Department d ON s.Dept_ID = d.Dept_Id
WHERE d.Dept_Name = 'CSE';

SELECT * FROM CSE_Students;