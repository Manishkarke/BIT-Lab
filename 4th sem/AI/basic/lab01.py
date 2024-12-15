# Write a program to find the greatest numbers entered by user
nums = list(map(int, input("Enter any four number seperated by ',': ").split(",")));
greatestNum = nums[0]
for x in nums:
    if(x > greatestNum):
        greatestNum = x
print("The greatest number among the four numbers is ", greatestNum );