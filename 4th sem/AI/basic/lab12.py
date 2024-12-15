def remove_strip(lst, wordToRemove):
    new_list = [i.strip() for i in lst if i.strip() != wordToRemove]
    return new_list

lst = [" Quantum Computing ", "  Blockchain", " Artificial Neural Networks ", "Cryptography  "]

print(f"Before removing and stripping whitespaces: {lst}")
print(f"After removing and stripping whitespaces: {remove_strip(lst, "Blockchain")}")
