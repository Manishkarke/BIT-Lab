# WAP to calculate factorial of given number using for loop

num = int(input("Enter the number of which you want factorial: "))

fact = 1;
for x in range(2, num + 1):
    fact *= x
    
print("Fatorial of",num, "is", fact)