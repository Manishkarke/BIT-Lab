# wap that make a copy of text file "ram.txt"

def makeACopy(currentFile, newFile):
    try:
        with open(currentFile, 'r') as file:
            content = file.read()
        
        with open(newFile, 'w') as file:
            file.write(content)
            
        print("Content of ", currentFile, "has been copied to",newFile, "successfully.")
    except FileNotFoundError:
        print("There is no file with name", currentFile)
        
makeACopy("ram.txt", "ram2.txt")