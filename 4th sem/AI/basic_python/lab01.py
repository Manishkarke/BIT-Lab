# Write program to find the greatest of 4 numbers entered by user
a, b, c, d = [int(i) for i in input("Enter four numbers: ").split()]
print(f"Greatest number among {a}, {b}, {c}, {d} = {max(a, b, c, d)}")

print("-------- Program by Manish Karki. --------")