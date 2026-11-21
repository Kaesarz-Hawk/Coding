-- ============================================================================
-- LAB 2: Banking Database Schema, Exact Data & Queries (Q1 - Q14)
-- NOTE: Run this setup first; Labs 3 and 5 (Part 1) also use banking_db.
-- ============================================================================

DROP DATABASE IF EXISTS banking_db;
CREATE DATABASE banking_db;
USE banking_db;

-- 1. branch relation
CREATE TABLE branch (
    branch_name VARCHAR(30) PRIMARY KEY,
    branch_city VARCHAR(30),
    assets      BIGINT
);

INSERT INTO branch VALUES
('Brighton',   'Brooklyn',   7100000),
('Downtown',   'Brooklyn',   9000000),
('Mianus',     'Horseneck',  400000),
('North Town', 'Rye',        3700000),
('Perryridge', 'Horseneck',  1700000),
('Pownal',     'Bennington', 300000),
('Redwood',    'Palo Alto',  2100000),
('Round Hill', 'Horseneck',  8000000);

-- 2. account relation
CREATE TABLE account (
    account_number VARCHAR(15) PRIMARY KEY,
    branch_name    VARCHAR(30),
    balance        INT
);

INSERT INTO account VALUES
('A-101', 'Downtown',   500),
('A-102', 'Perryridge', 400),
('A-201', 'Brighton',   900),
('A-215', 'Mianus',     700),
('A-217', 'Brighton',   750),
('A-222', 'Redwood',    700),
('A-305', 'Round Hill', 350);

-- 3. customer relation
CREATE TABLE customer (
    customer_name   VARCHAR(30) PRIMARY KEY,
    customer_street VARCHAR(30),
    customer_city   VARCHAR(30)
);

INSERT INTO customer VALUES
('Adams',    'Spring',    'Pittsfield'),
('Brooks',   'Senator',   'Brooklyn'),
('Curry',    'North',     'Rye'),
('Glenn',    'Sand Hill', 'Woodside'),
('Green',    'Walnut',    'Stamford'),
('Hayes',    'Main',      'Harrison'),
('Johnson',  'Alma',      'Palo Alto'),
('Jones',    'Main',      'Harrison'),
('Lindsay',  'Park',      'Pittsfield'),
('Smith',    'North',     'Rye'),
('Turner',   'Putnam',    'Stamford'),
('Williams', 'Nassau',    'Princeton');

-- 4. depositor relation
CREATE TABLE depositor (
    customer_name  VARCHAR(30),
    account_number VARCHAR(15),
    PRIMARY KEY (customer_name, account_number)
);

INSERT INTO depositor VALUES
('Hayes',   'A-102'),
('Johnson', 'A-101'),
('Johnson', 'A-201'),
('Jones',   'A-217'),
('Lindsay', 'A-222'),
('Smith',   'A-215'),
('Turner',  'A-305');

-- 5. loan relation
CREATE TABLE loan (
    loan_number VARCHAR(15) PRIMARY KEY,
    branch_name VARCHAR(30),
    amount      INT
);

INSERT INTO loan VALUES
('L-11', 'Round Hill', 900),
('L-14', 'Downtown',   1500),
('L-15', 'Perryridge', 1500),
('L-16', 'Perryridge', 1300),
('L-17', 'Downtown',   1000),
('L-23', 'Redwood',    2000),
('L-93', 'Mianus',     500);

-- 6. borrower relation
CREATE TABLE borrower (
    customer_name VARCHAR(30),
    loan_number   VARCHAR(15),
    PRIMARY KEY (customer_name, loan_number)
);

INSERT INTO borrower VALUES
('Adams',    'L-16'),
('Curry',    'L-93'),
('Hayes',    'L-15'),
('Johnson',  'L-14'),
('Jones',    'L-17'),
('Smith',    'L-11'),
('Smith',    'L-23'),
('Williams', 'L-17');


-- ============================================================================
-- LAB 2 QUERIES (Q1 - Q14)
-- ============================================================================

-- Q1. Find the names of all branches in the "loan" relation.
SELECT branch_name FROM loan;

-- Q2. Find all loan numbers for loans at "Perryridge" with amount > 300.
SELECT loan_number FROM loan
WHERE branch_name = 'Perryridge' AND amount > 300;

-- Q3. Find all loan numbers at either "Perryridge" or "Downtown" branch.
SELECT loan_number FROM loan
WHERE branch_name = 'Perryridge' OR branch_name = 'Downtown';

-- Q4. Find all loan numbers at "Perryridge", "Downtown", or "Mianus" branch.
SELECT loan_number FROM loan
WHERE branch_name IN ('Perryridge', 'Downtown', 'Mianus');

-- Q5. Find names of customers NOT from "Stamford", "Princeton", or "Harrison".
SELECT customer_name FROM customer
WHERE customer_city NOT IN ('Stamford', 'Princeton', 'Harrison');

-- Q6. Find largest, minimum, and average account balance in "account".
SELECT MAX(balance) AS Maximum,
       MIN(balance) AS Minimum,
       AVG(balance) AS Average
FROM account;

-- Q7. Find the total number of customers from "customer" relation.
SELECT COUNT(customer_name) AS 'Total no. of customers'
FROM customer;

-- Q8. Find loan numbers with loan amounts between 400 and 800.
SELECT loan_number FROM loan
WHERE amount BETWEEN 400 AND 800;

-- Q9. Find names of all customers whose name starts with "G".
SELECT customer_name FROM customer
WHERE customer_name LIKE 'G%';

-- Q10. Find names of all customers whose name ends with "s".
SELECT customer_name FROM customer
WHERE customer_name LIKE '%s';

-- Q11. Find names of customers whose name has "o" in 2nd position.
SELECT customer_name FROM customer
WHERE customer_name LIKE '_o%';

-- Q12. Find names of customers with "o" in any position except 1st and last.
SELECT customer_name FROM customer
WHERE customer_name LIKE '_%o%_';

-- Q13. Find the length of the name of all customers.
SELECT customer_name, LENGTH(customer_name) AS Length
FROM customer;

-- Q14. Find 1st three characters of each customer name.
SELECT customer_name, SUBSTR(customer_name, 1, 3) AS First_Three
FROM customer;