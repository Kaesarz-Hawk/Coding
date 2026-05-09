# 1-50 .... print divisible by 2
# 1 - 30 .... even number print
# 1 - 20 .... odd print
# 0 - 100 .... 0....5..10...15
# 5 friends name input and output 5 names 



# 1.
# i=0
# for i in range(1,51):
#     if i%2==0:
#         print(i)

# #2.
# j=0
# for j in range(1,31):
#     if j%2==0:
#         print(j)

# #3.
# k=0
# for k in range(1,21):
#     if k%2==1:
#         print(k)

# #4.
# l=0
# for l in range (0,101,5):
#     print(l)

#5.

#take 5 friends name input and output 5 names as 1. name1 = input("Enter name of friend 1: ")
# name2 = input("Enter name of friend 2: ")
# name3 = input("Enter name of friend 3: ")
# name4 = input("Enter name of friend 4: ")
# name5 = input("Enter name of friend 5: ")


for i in range(5):
    print("Enter name of friend", i+1, end=": ")
    name = input()
    print("Friend", i+1, "name is", name)


    