# 1. Write a python program to add two numbers.
# 2. Write a python program to find remainder when a number is divided by z.
# 3. Check the type of variable assigned using input () function.
# 4. Use comparison operator to find out whether ‘a’ given variable a is greater than
# ‘b’ or not. Take a = 34 and b = 80
# 5. Write a python program to find an average of two numbers entered by the user.
# 6. Write a python program to calculate the square of a number entered by the user.

number1 = int(input("the first number is "))
number2 = int(input("the second number is "))
sum = number1 + number2
print(sum)

# 2.
z = int(input())
print(sum%z)

# 3.

a = input("enter a value")
print(type(a))

# 4.
a = int(input("Enter number 1: "))
b = int(input("Enter number 2: "))

print("a is greater than b is", a<b)

# 5.
avg = sum/2
print("The average of two numbers is", avg)
#6
a= float(input("Enter a number: "))
square = a*a
print("The square of the number is", square)