# WAP to find whether a given username contains less than 10 character or not

userName = input("Enter your username: ")

if(len(userName) < 10):
    print(userName + " contains less than 10 characters.")
else:
    print(userName + " contains", len(userName),"characters.")