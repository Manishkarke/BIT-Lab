# Repeat the lab 14 program for a list of such words to be sensored.
def censorWords(fileName, wordList):
    try:
        with open(fileName, "r") as file:
            content = file.read()
            print(f"Initial content of {fileName}: {content}")
            
        for word in wordList:
            content = content.replace(word, ("*" * len(word)))
        
        with open(fileName, 'w') as file:
            file.write(content)
        
        
        print(f"\nCensored content of {fileName}: {content}")
        print("\nThe content has been updated successfully.")
    except FileNotFoundError:
        print("file with name '",fileName,"' not found.")
wordList = ["murder", "violence", "crime"]

censorWords("lab15.txt", wordList)