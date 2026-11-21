-- ============================================================================
-- LAB 5 (PART 1): Multi-Table Queries, Calculations & Deletions (banking_db)
-- Prerequisite: Run lab2_banking_queries.sql first.
-- ============================================================================

USE banking_db;
SET SQL_SAFE_UPDATES = 0;

-- Q1. Fetch all customer names in alphabetical order who live in Harrison.
SELECT customer_name FROM customer
WHERE customer_city = 'Harrison'
ORDER BY customer_name ASC;

-- Q2. List all customers in alphabetical order with a loan at Perryridge.
SELECT borrower.customer_name
FROM borrower, loan
WHERE borrower.loan_number = loan.loan_number
  AND loan.branch_name = 'Perryridge'
ORDER BY borrower.customer_name ASC;

-- Q3. Find all customers with a loan: names, loan numbers, and loan amounts.
SELECT borrower.customer_name, borrower.loan_number, loan.amount
FROM borrower
INNER JOIN loan ON borrower.loan_number = loan.loan_number;

-- Q5. Find the name of all distinct branches from "loan" table.
SELECT DISTINCT branch_name FROM loan;

-- Q6. Find loan no and 5 times amount, renamed as "total_balance".
SELECT loan_number, 5 * amount AS total_balance FROM loan;

-- Q7. Increase all loan amounts by 5 percent from loan relation.
SELECT loan_number, amount * 1.05 AS Increased_Amount FROM loan;

-- Q8. Give 6 percent interest for all loans with amount over 1000.
SELECT loan_number, amount * 1.06 AS Amount_With_Interest
FROM loan
WHERE amount > 1000;

-- Q9. Delete all information of Perryridge branch from branch table.
DELETE FROM branch WHERE branch_name = 'Perryridge';

-- Q10. Delete all loans with loan amounts between 1300 and 1500.
DELETE FROM loan WHERE amount BETWEEN 1300 AND 1500;


-- ============================================================================
-- LAB 5 (PART 2): Constraints, Foreign Keys & HR Queries (company_db)
-- ============================================================================

DROP DATABASE IF EXISTS company_db;
CREATE DATABASE company_db;
USE company_db;
SET SQL_SAFE_UPDATES = 0;

-- Create Department Table
CREATE TABLE Department (
    Dept_Id   VARCHAR(10) PRIMARY KEY,
    Dept_Name VARCHAR(100) NOT NULL,
    Location  VARCHAR(50)
);

-- Create Employee Table with all required constraints
CREATE TABLE Employee (
    Emp_Id       INT PRIMARY KEY,
    Emp_Name     VARCHAR(100) NOT NULL,
    Dept_Id      VARCHAR(10),
    Salary       DECIMAL(10, 2) CHECK (Salary > 10000),
    Joining_Date DATE DEFAULT (CURRENT_DATE),
    Email        VARCHAR(100) UNIQUE,
    FOREIGN KEY (Dept_Id) REFERENCES Department(Dept_Id)
);

-- Insert Data
INSERT INTO Department VALUES
('HR', 'Human Resource',         'Dhaka'),
('IT', 'Information Technology', 'Chittagong');

INSERT INTO Employee VALUES
(101, 'Rahim',   'HR', 55000, '2026-01-10', 'rahim@gmail.com'),
(102, 'Karim',   'IT', 42000, '2026-02-15', 'karim@gmail.com'),
(103, 'Nabila',  'HR', 68000, '2026-03-05', 'ayesha@gmail.com'),
(104, 'Sumaiya', 'IT', 75000, '2026-04-20', 'nabila@gmail.com'),
(105, 'Hasan',   'IT', 48000, '2026-05-12', 'hasan@gmail.com');

-- Q1. Fetch names of all employees in alphabetical order in HR department.
SELECT Emp_Name FROM Employee
WHERE Dept_Id = 'HR'
ORDER BY Emp_Name ASC;

-- Q2. Find all employees who belong to a department (name, Dept_Id, salary).
SELECT Emp_Name, Dept_Id, Salary FROM Employee
WHERE Dept_Id IS NOT NULL;

-- Q3. Find the names/IDs of all departments from the Employee table.
SELECT DISTINCT Dept_Id FROM Employee;

SELECT DISTINCT d.Dept_Name
FROM Employee e
INNER JOIN Department d ON e.Dept_Id = d.Dept_Id;

-- Q4. Employee IDs and salaries multiplied by 5, aliased as Total_Salary.
SELECT Emp_Id, Salary * 5 AS Total_Salary FROM Employee;

-- Q5. Increase salary of every employee by 5% and display Emp_Id & new salary.
SELECT Emp_Id, Salary * 1.05 AS Updated_Salary FROM Employee;

-- Q6. Calculate a 6% salary increase for employees with salary > 30,000.
SELECT Emp_Id, Emp_Name, Salary * 1.06 AS Increased_Salary
FROM Employee
WHERE Salary > 30000;

-- Q7. Names & salaries of employees who joined after Jan 1, 2025 (Salary DESC).
SELECT Emp_Name, Salary FROM Employee
WHERE Joining_Date > '2025-01-01'
ORDER BY Salary DESC;

-- Q8. Delete all employee records belonging to the IT department.
DELETE FROM Employee WHERE Dept_Id = 'IT';