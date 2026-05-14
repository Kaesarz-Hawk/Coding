
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

print("Number a is :" , a)
print("Number b is :" , b)
sum = a + b
print("The sum of a and b is :" , sum)
diff = a - b
print("The difference of a and b is :" , diff)
prod = a * b
print("The product of a and b is :" , prod)
quot = a / b
print("The quotient of a and b is :" , quot)
mod = a % b
print("The modulus of a and b is :" , mod)
exp = a ** b
print("The exponentiation of a to the power b is :" , exp)
floordiv = a // b
print("The floor division of a by b is :" , floordiv)
max_num = max(a, b)
print("The maximum of a and b is :" , max_num)
min_num = min(a, b)
print("The minimum of a and b is :" , min_num)
avg = (a + b) / 2
print("The average of a and b is :" , avg)
import math
sqrt_a = math.sqrt(a)
sqrt_b = math.sqrt(b)
print("The square root of a is :" , sqrt_a)
print("The square root of b is :" , sqrt_b)
print("\n")
Hisname = "Kawsar"
Hername = "notyet"
new_name = Hisname[:4] + Hername[1:]
print("They are together known as :" , new_name)

import pyttsx3
engine = pyttsx3.init()
voices = engine.getProperty('voices') 
engine.setProperty('rate', 128)
text = ("Kayes loves her so much even I python knows it... they are meant to be together but the girl is blind to see it Ai is praying" \
" that one day she will realize kayes is the one for her... kayes will never give up on her no matter what happens...")
engine.say(text)
engine.runAndWait() 