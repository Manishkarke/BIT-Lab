# Wap to find out whether a student is failed or pass, if it requires total 40% and at
# least 33% in each subject to pass. Assume three subject and take marks as an input
# from user
sub1, sub2, sub3 = [float(i) for i in input("Enter the marks of three subjects: ").split()]
totalPercentage = ((sub1 + sub2 + sub3) / 300) * 100

if(all(mark >= 33 for mark in [sub1, sub2, sub3]) and totalPercentage >= 40):
    print("Congratulation!! You passed the exam.")
else:
    print("Sorry, You failed.")

print("-------- Program by Manish Karki. --------")