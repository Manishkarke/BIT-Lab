# WAP to calculate grade of student fromhis marks from the following scheme
# 90 - 100 => Excellent
# 80 - 90 => A
# 70 - 80 -> B
# 60 - 70 => C
# 50 - 60 => D
# < 50 => F

marks = list(map(float, input("Enter your marks seperated by ',': ").split(",")))

total = (sum(marks) / (len(marks) * 100)) * 100

grade = ""

if(total <= 100 and total >= 90):
    grade = "Excellent"
elif(total >= 80 and total < 90):
    grade = "A"
elif(total >= 70 and total < 80):
    grade = "B"
elif(total >= 60 and total < 70):
    grade = "C"
elif(total >= 50 and total < 60):
    grade = "D"
elif(total >= 0 and total < 50):
    grade = "F"

print("Your grade is "+ grade)