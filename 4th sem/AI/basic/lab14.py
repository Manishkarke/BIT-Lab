# A file contains a word "donkey" multiple times.
# We need to WAP which replace this word with ###### by operating in the same file

def findAndReplace(fileName, oldWord, newWord):
    try:
        with open(fileName, "r") as file:
            content = file.read()
            print(f"Initial Content of {fileName} is '{content}'")
        
        updatedContent = content.replace(oldWord, newWord)
        
        with open(fileName, 'w') as file:
            file.write(updatedContent)
            
        print(f"\nAfter Content of {fileName} is '{updatedContent}'")
        print("\nThe content has been updated successfully.")
    except FileNotFoundError:
        print("file with name '",fileName,"' not found.")
        
findAndReplace("sample.txt", "donkey", "######")