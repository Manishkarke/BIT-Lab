# WAP to find the sum of 1st n natural number using while loop
num = int(input("Enter the number: "))
sum =0

while num >= 1:
    sum+= num
    num -=1

print("Sum of first n natural numbers:",sum)