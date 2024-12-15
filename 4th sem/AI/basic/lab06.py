# WAP to print multiplication table of given number using for loop and also using while loop
num = int(input("Enter the number of which you want multiplication table: "))

print("Using For loop: ")
for x in range(1, 11):
    print(num, "*",x, "=", num * x)

print("Using while loop:")
i = 1    
while i <= 10:
    print(num, "*",i, "=", num * i)
    i += 1