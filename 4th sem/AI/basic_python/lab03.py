# A spam comment is defined as the text containing the following words “make a lot
# of money”, “Subscribe this”, “click this”. Wap to detect this spam
spams = ["make a lot of money", "Subscribe this", "click this"]
isSpam = False

userInput = input("Enter your comment: ")
for spam in spams:
    if(spam.lower() in userInput.lower()):
        print("This is spam.")
        isSpam = True
        break

if not isSpam:
    print("This is not a spam.")