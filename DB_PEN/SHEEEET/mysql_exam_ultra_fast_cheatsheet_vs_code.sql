-- ============================================================================
-- KH MYSQL LAB EXAM ULTRA-FAST CHEATSHEET (VS CODE QUICK LOOKUP)
-- Search tags with Ctrl+F: [START] [DDL] [DML] [FILTER] [LIKE] [MATH]
--                          [GROUP] [JOIN] [SET] [SUBQUERY] [VIEW] [VIVA]
-- ============================================================================

-- [START] RUN THIS FIRST IN EVERY LAB EXAM
CREATE DATABASE IF NOT EXISTS exam_db;
USE exam_db;
SET SQL_SAFE_UPDATES = 0;

-- CLAUSE WRITING ORDER:
-- SELECT -> FROM -> WHERE -> GROUP BY -> HAVING -> ORDER BY -> LIMIT OFFSET


-- ============================================================================
-- [DDL] CREATE TABLE, CONSTRAINTS & ALTER
-- ============================================================================
CREATE TABLE Parent (
    Dept_Id   VARCHAR(10) PRIMARY KEY,
    Dept_Name VARCHAR(50) NOT NULL
);

CREATE TABLE Child (
    Emp_Id       INT PRIMARY KEY,
    Emp_Name     VARCHAR(100) NOT NULL,
    Email        VARCHAR(100) UNIQUE,
    Salary       DECIMAL(10, 2) CHECK (Salary > 10000),
    Joining_Date DATE DEFAULT (CURRENT_DATE),
    Dept_Id      VARCHAR(10),
    FOREIGN KEY (Dept_Id) REFERENCES Parent(Dept_Id)
);

ALTER TABLE Child  ADD COLUMN Age INT;                                -- Add at end
ALTER TABLE Child  ADD COLUMN Phone VARCHAR(20) AFTER Emp_Name;       -- Add after col
ALTER TABLE Parent CHANGE COLUMN Dept_Name D_Name VARCHAR(60);        -- Rename + type
ALTER TABLE Child  DROP COLUMN Phone;                                 -- Drop column


-- ============================================================================
-- [DML] INSERT, UPDATE (NULL), DELETE
-- ============================================================================
INSERT INTO Parent VALUES ('HR', 'Human Resource'), ('IT', 'Info Tech');

UPDATE Child SET Dept_Id = 'HR' WHERE Dept_Id IS NULL;                -- Always IS NULL
UPDATE Child SET Salary = Salary * 1.05 WHERE Emp_Id = 101;

DELETE FROM Child WHERE Dept_Id = 'IT';
DELETE FROM Child WHERE Salary BETWEEN 1300 AND 1500;


-- ============================================================================
-- [FILTER] & [LIKE] WILDCARDS, IN, BETWEEN, ORDER BY
-- ============================================================================
SELECT DISTINCT Dept_Id FROM Child;
SELECT * FROM Child WHERE Dept_Id IN ('HR', 'IT');
SELECT * FROM Child WHERE Dept_Id NOT IN ('HR', 'IT');
SELECT * FROM Child WHERE Salary BETWEEN 40000 AND 70000;
SELECT * FROM Child WHERE Joining_Date > '2025-01-01' ORDER BY Salary DESC;

-- LIKE patterns (% = 0+ chars, _ = exactly 1 char):
SELECT * FROM Child WHERE Emp_Name LIKE 'G%';        -- Starts with G
SELECT * FROM Child WHERE Emp_Name LIKE '%s';        -- Ends with s
SELECT * FROM Child WHERE Emp_Name LIKE '_o%';       -- 'o' in 2nd position
SELECT * FROM Child WHERE Emp_Name LIKE '_%o%_';     -- 'o' except 1st & last


-- ============================================================================
-- [MATH] ARITHMETIC, ALIASES & STRING FUNCTIONS
-- ============================================================================
SELECT Emp_Id, Salary * 5    AS Total_Salary FROM Child;              -- 5 times
SELECT Emp_Id, Salary * 1.05 AS Plus_5_Pct   FROM Child;              -- +5%
SELECT Emp_Id, Salary * 1.06 AS Plus_6_Pct   FROM Child WHERE Salary > 30000;

SELECT Emp_Name, LENGTH(Emp_Name) AS Len, SUBSTR(Emp_Name, 1, 3) AS First3
FROM Child;


-- ============================================================================
-- [GROUP] AGGREGATES, GROUP BY & HAVING
-- ============================================================================
SELECT MAX(Salary), MIN(Salary), AVG(Salary), SUM(Salary), COUNT(*) FROM Child;

SELECT Dept_Id, COUNT(*) AS Total_Emp, AVG(Salary) AS Avg_Sal
FROM Child
GROUP BY Dept_Id
HAVING COUNT(*) > 1;                                                  -- Filter groups


-- ============================================================================
-- [JOIN] ALL 5 LAB JOIN TYPES
-- ============================================================================
SELECT * FROM Parent, Child;                                          -- Cartesian
SELECT c.Emp_Name, p.Dept_Name FROM Child c INNER JOIN Parent p ON c.Dept_Id = p.Dept_Id;
SELECT * FROM Parent NATURAL JOIN Child;
SELECT * FROM Parent LEFT OUTER JOIN Child  ON Parent.Dept_Id = Child.Dept_Id;
SELECT * FROM Parent RIGHT OUTER JOIN Child ON Parent.Dept_Id = Child.Dept_Id;


-- ============================================================================
-- [SET] UNION, INTERSECT (IN), EXCEPT (NOT IN)
-- ============================================================================
-- Either A or B or both:
(SELECT customer_name FROM borrower) UNION (SELECT customer_name FROM depositor);

-- Both A and B (works on all MySQL versions):
SELECT DISTINCT customer_name FROM borrower
WHERE customer_name IN (SELECT customer_name FROM depositor);

-- Only A, NOT B:
SELECT DISTINCT customer_name FROM depositor
WHERE customer_name NOT IN (SELECT customer_name FROM borrower);


-- ============================================================================
-- [SUBQUERY] LAB 6 EXAM SPECIALS (TOP-1, 2ND HIGHEST, DUPLICATES, COMPARE)
-- ============================================================================
-- 1. Department with highest number of students:
SELECT Dept_Id, COUNT(*) AS cnt FROM Child GROUP BY Dept_Id ORDER BY cnt DESC LIMIT 1;

-- 2. Second-highest Salary / CGPA:
SELECT MAX(Salary) AS Second_Highest FROM Child
WHERE Salary < (SELECT MAX(Salary) FROM Child);

-- 3. Rows with the exact same Salary / CGPA (duplicates):
SELECT * FROM Child
WHERE Salary IN (SELECT Salary FROM Child GROUP BY Salary HAVING COUNT(*) > 1);

-- 4. Greater than specific ID's value:
SELECT * FROM Child
WHERE Salary > (SELECT Salary FROM Child WHERE Emp_Id = 102);


-- ============================================================================
-- [VIEW] CREATE & QUERY VIEWS
-- ============================================================================
CREATE OR REPLACE VIEW HR_View AS
SELECT Emp_Id, Emp_Name, Salary FROM Child WHERE Dept_Id = 'HR';

SELECT * FROM HR_View;


-- ============================================================================
-- [VIVA] 5-SECOND REMINDERS
-- 1. WHERE = row filter (before GROUP BY) | HAVING = group filter (after GROUP BY)
-- 2. DELETE = selected rows | TRUNCATE = all rows (keeps table) | DROP = whole table
-- 3. PK = 1 per table, no NULL | UNIQUE = multiple allowed, NULL ok
-- 4. VIEW = virtual table (stores query only, shows live data)
-- 5. COUNT(*) counts NULLs | COUNT(col) skips NULLs
-- ============================================================================