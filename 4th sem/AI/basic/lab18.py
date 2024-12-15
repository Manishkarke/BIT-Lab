# WAP to wipeout the contains of a file using python
def wipeFile(fileName):
    try:
        with open(fileName, 'r') as file:
            content = file.read();
            
            print("before wiping,\nfile content:", content)
        with open(fileName, 'w') as file:
            content = ""
            file.write(content)
            print("after wiping,\nfile content:", content)
    except FileNotFoundError:
        print(fileName, "is not detected.")
        
wipeFile("sample.txt")