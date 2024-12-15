# A file contains a word "donkey" multiple times.
# We need to WAP which replace this word with ###### by operating in the same file

def findAndReplace(fileName, oldWord, newWord):
    try:
        with open(fileName, "r") as file:
            content = file.read()
        
        updatedContent = content.replace(oldWord, newWord)
        
        with open(fileName, 'w') as file:
            file.write(updatedContent)
            
        print("The content has been updated successfully.")
    except FileNotFoundError:
        print("file with name '",fileName,"' not found.")
        
findAndReplace("sample.txt", "donkey", "######")