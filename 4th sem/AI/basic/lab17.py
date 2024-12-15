# WAP to find out whether file is identical and matches the contains of another file ?

def compareFile(f1Name, f2Name):
    try:
        with open(f1Name, 'r') as f1, open(f2Name, 'r') as f2:
            content1 = f1.read()
            content2 = f2.read()
        print(f"content of {f1Name}: {content1}\ncontent of {f2Name}: {content2}\n")
        if(content1 == content2):
            print("Both files are identical.")
        else:
            print("They are not identical")
    except FileNotFoundError:
        print("file not found.")
    
        
compareFile('ram.txt', 'ram2.txt')