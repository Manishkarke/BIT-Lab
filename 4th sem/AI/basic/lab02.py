# WAP to find out whether a student failed or pass, if it requires total 40% and atleast 33% in each subject to pass. Assume three subjects ans fake marks as an input from a user

marks = input("Enter marks of three subjects seperate each marks with comma: ")

marks = list(map(float, marks.split(",")))
total = sum(marks);
isPass = True
for mark in marks:
    if(mark < 33):
        isPass= False
percentage = (total / len(marks) * 100) * 100
if(isPass == True and percentage >= 44):
    print("You passed!");
else:
    print("You failed!")

