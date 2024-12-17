def trainNaiveBayes(trainData):
    numDocs = len(trainData)
    classCounts = {label: sum(1 for _, lbl in trainData if lbl == label) for label in set(lbl for _, lbl in trainData)}
    classProbs = {label: classCounts[label] / numDocs for label in classCounts}
    vocab = set(word for email, _ in trainData for word in email)
    wordProbs = {label: {} for label in classCounts}
    for label in classCounts:
        classDocs = [email for email, lbl in trainData if lbl == label]
        classWords = [word for doc in classDocs for word in doc]
        totalWords = len(classWords)
        for word in vocab:
            wordCounts = classWords.count(word)
            wordProbs[label][word] = (wordCounts + 1) / (totalWords + len(vocab))
    return {'classProbs': classProbs, 'wordProbs': wordProbs}

def classifyEmail(email, model):
    classProbs = model['classProbs']
    wordProbs = model['wordProbs']
    maxProb = -1
    predictedClass = None
    for label in classProbs:
        prob = classProbs[label]
        for word in email:
            prob *= wordProbs[label].get(word, 1e-10)
        if prob > maxProb:
            maxProb = prob
            predictedClass = label
    return predictedClass

# New training data with a different context
trainData = [
    (["discount", "electronics", "buy", "now"], 1),
    (["team", "meeting", "agenda", "discussion"], 0),
    (["limited", "time", "offer", "save", "money"], 1),
    (["important", "project", "deadline", "client", "update"], 0),
    (["special", "promotion", "50%", "off", "laptop"], 1),
    (["monthly", "report", "sales", "analysis"], 0)
]

print("Enter the words of the email to classify (separate by commas):")
testEmail = input().split(",") 

# Train the model with the new training data
model = trainNaiveBayes(trainData)

# Classify the test email
predictedClass = classifyEmail(testEmail, model)

# Output with updated response
if predictedClass == 1:
    print("This email seems to be a SPAM message.")
else:
    print("This email appears to be a valid message.")
