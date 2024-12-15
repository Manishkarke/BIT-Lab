# Wap to demonstrate number swap.

lst1 = [10, 20, 30, 40, 50]
lst2 = [60, 70, 80, 90, 20]

for i in range(0, len(lst1)):
    print(f"Before swapping number at {i} index:\nList 1 = {lst1}\nList 2 = {lst2}")
    lst1[i], lst2[i] = lst2[i], lst1[i]
    print(f"After swapping number at {i} index:\nList 1 = {lst1}\nList 2 = {lst2}\n")