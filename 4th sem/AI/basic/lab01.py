# Write a program to find the greatest numbers entered by user
nums = input("Enter any four number seperated by ',': ");
nums = nums.split(",")
greatestNum = int(nums[0])
for x in nums:
    if(int(x) > greatestNum):
        greatestNum = x
print("The greatest number among the four numbers is ", greatestNum );