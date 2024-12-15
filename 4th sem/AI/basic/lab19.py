import os 
def renameFile(oldName, newName):
    try:
        os.rename(oldName, newName)
        print(f"File renamed successfully from '{oldName}' to '{newName}'.")
    except FileNotFoundError:
        print(f"Error: File '{oldName}' not found.")
    except FileExistsError:
        print(f"A file with the name '{newName}' already exists.")

renameFile("sample.txt", "Renamed_by_python.txt")