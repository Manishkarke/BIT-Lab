# WAP to read a text from a given file and find out whether it contains a word twinkle
def findWord(fileName, word):
    try:
        with open(fileName, "r") as file:
            content = file.read()
            print(f"{fileName} content: {content}")
            if(word.lower() in content.lower()):
                print("Yes, The file contains the word twinkle")
            else:
                print("No the file doesn't contains the word 'twinkle'")
    except FileNotFoundError:
        print("File with name",fileName,"not found.")
        
findWord("sample.txt", "twinkle")