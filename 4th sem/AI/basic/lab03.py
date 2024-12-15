# A spam comment is defined as the text containing the following words "Make a lot of money", "Subscribe this", "click this". WAP to detect this spam

message = input("Enter your message: ").casefold();

keywords= ["make a lot of money", "subscribe this", "click this"]

isSpam = False

for x in keywords:
    if(message.find(x)):
        isSpam = True
        break

if(isSpam):
    print("The message is a spam.")
else:
    print("The message is not a spam")