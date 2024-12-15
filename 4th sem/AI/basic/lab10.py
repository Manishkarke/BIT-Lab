# WAP to print star patterns

num = int(input("Enter the number of rows: "))

for x in range(num):
    space = num - x - 1
    stars = 2 * x + 1
    print(" " * space + "*" * stars)
    