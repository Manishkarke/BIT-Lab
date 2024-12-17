def buildParseTree(rule, tokens):
    if len(tokens) == 0 and rule == "Sentence":
        return ("Sentence", [])

    for production in grammar[rule]:
        productionTokens = production.split()

        if productionTokens == [tokens[0]]:
            # Terminal rule (matching token)
            root = (rule, [tokens[0]])
            remainingTokens = tokens[1:]
            return root, remainingTokens

        elif len(productionTokens) == 2:
            # Non-terminal rule with two parts
            leftChild, remainingTokens = buildParseTree(productionTokens[0], tokens)
            if remainingTokens:
                rightChild, remainingTokens = buildParseTree(productionTokens[1], remainingTokens)
                root = (rule, [leftChild, rightChild])
                return root, remainingTokens

    return None, tokens

def printTree(node, level=0):
    if node is None:
        return
    if isinstance(node, tuple):
        rule, children = node
        print("  " * level + rule)
        for child in children:
            printTree(child, level + 1)
    else:
        print("  " * level + node)


# Grammar definition
grammar = {
    "Sentence": ["NounPhrase VerbPhrase"],
    "NounPhrase": ["Noun", "Determiner Noun"],
    "VerbPhrase": ["Verb", "Verb NounPhrase"],
    "Noun": ["dog", "cat"],
    "Determiner": ["the", "a"],
    "Verb": ["eats", "chases"]
}

# User input for sentence
sentence = input("Enter a sentence: ")
tokens = sentence.split()

# Generate parse tree
parseTree, remainingTokens = buildParseTree("Sentence", tokens)

if not remainingTokens:
    print("Parse Successful!")
    printTree(parseTree)
else:
    print("Parse Failed.")
