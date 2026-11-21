-- ============================================================================
-- LAB 3: GROUP BY, HAVING, Set Operations & ALTER COLUMN (banking_db)
-- Prerequisite: Run lab2_banking_queries.sql first to create banking_db.
-- ============================================================================

USE banking_db;

-- Q1. Find the number of customers from all cities in "customer" relation.
SELECT customer_city, COUNT(customer_name) AS 'Total no. of customers'
FROM customer
GROUP BY customer_city;

-- Q2. Find the total no. of loans from each branch in "loan" relation.
SELECT branch_name, COUNT(loan_number) AS 'No. of loans'
FROM loan
GROUP BY branch_name;

-- Q3. Find total loan amount of each branch where total amount > 1200.
SELECT branch_name, SUM(amount) AS Total_Amount
FROM loan
GROUP BY branch_name
HAVING SUM(amount) > 1200;

-- Q4. Find the average loan amount from each branch.
SELECT branch_name, AVG(amount) AS 'Average amount'
FROM loan
GROUP BY branch_name;

-- Q5. Find the total loan amount of each branch.
SELECT branch_name, SUM(amount) AS 'Total amount'
FROM loan
GROUP BY branch_name;

-- Q6. Find the total number of tuples for loan and account relations.
SELECT COUNT(*) AS Total_Loans FROM loan;
SELECT COUNT(*) AS Total_Accounts FROM account;

-- Q7. Find average account balance of each branch where average > 500.
SELECT branch_name, AVG(balance) AS Average_Balance
FROM account
GROUP BY branch_name
HAVING AVG(balance) > 500;

-- Q8. Customers who have either a loan or an account or both.
(SELECT customer_name FROM borrower)
UNION
(SELECT customer_name FROM depositor);

-- Q9. Customers who have both a loan and an account.
-- Option A (MySQL 8.0.31+):
(SELECT customer_name FROM borrower)
INTERSECT
(SELECT customer_name FROM depositor);

-- Option B (Works on ALL MySQL / MariaDB versions):
SELECT DISTINCT customer_name
FROM borrower
WHERE customer_name IN (SELECT customer_name FROM depositor);

-- Q10. Customers who have only an account, not any loan.
SELECT DISTINCT customer_name
FROM depositor
WHERE customer_name NOT IN (SELECT customer_name FROM borrower);

-- Q11. Change column name "branch_city" of branch relation to "city".
ALTER TABLE branch
CHANGE COLUMN branch_city city VARCHAR(30);