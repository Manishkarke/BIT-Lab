# WAP to find if given number is prime or not

num = int(input("Enter the number: "));
isPrime = True
for i in range(2, int(num / 2)):
    if(num % i == 0):
        isPrime = False
        break

if(isPrime and num != 1):
    print(num,"is a prime number.")
else:
    print(num, "is not a prime number.")