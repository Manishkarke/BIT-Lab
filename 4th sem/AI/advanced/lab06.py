import math
import random

# Activation function: Sigmoid and its derivative
activateSigmoid = lambda val: 1 / (1 + math.exp(-val))  # Sigmoid activation
def sigmoidGradient(output):
    return output * (1 - output)  # Derivative using the output

# Initialize the neural network layers
def buildNetwork(numInputs, numHidden, numOutputs):
    model = []
    hiddenLayer = {
        'weights': [[random.uniform(-0.5, 0.5) for _ in range(numInputs)] for _ in range(numHidden)],
        'outputs': []
    }
    model.append(hiddenLayer)
    outputLayer = {
        'weights': [[random.uniform(-0.5, 0.5) for _ in range(numHidden)] for _ in range(numOutputs)],
        'outputs': []
    }
    model.append(outputLayer)
    return model

# Forward pass through the network
def forwardPass(model, inputVector):
    currentInputs = inputVector[:-1]  # Input features (excluding label)
    for layer in model:
        tempOutputs = []
        for neuronWeights in layer['weights']:
            activationSum = sum([currentInputs[idx] * neuronWeights[idx] for idx in range(len(currentInputs))])
            neuronOutput = activateSigmoid(activationSum)
            tempOutputs.append(neuronOutput)
        layer['outputs'] = tempOutputs  # Save outputs for the current layer
        currentInputs = tempOutputs
    return currentInputs  # Return final outputs

# Backpropagation for error calculation
def backwardPass(model, targetVector):
    for layerIdx in reversed(range(len(model))):
        currentLayer = model[layerIdx]
        errors = []
        if layerIdx != len(model) - 1:  # Hidden layer
            nextLayer = model[layerIdx + 1]
            for nodeIdx in range(len(currentLayer['weights'])):
                errorSum = sum(
                    nextLayer['weights'][k][nodeIdx] * nextLayer['delta'][k]
                    for k in range(len(nextLayer['weights']))
                )
                errors.append(errorSum)
        else:  # Output layer
            errors = [(targetVector[i] - currentLayer['outputs'][i]) for i in range(len(targetVector))]

        # Compute delta for the layer
        currentLayer['delta'] = [
            error * sigmoidGradient(currentLayer['outputs'][idx])
            for idx, error in enumerate(errors)
        ]


# Update the network's weights
def adjustWeights(model, inputVector, learningRate):
    for layerIdx, layer in enumerate(model):
        inputs = inputVector[:-1] if layerIdx == 0 else model[layerIdx - 1]['outputs']
        for neuronIdx in range(len(layer['weights'])):
            for inputIdx in range(len(inputs)):
                layer['weights'][neuronIdx][inputIdx] += (
                    learningRate * layer['delta'][neuronIdx] * inputs[inputIdx]
                )

# Train the neural network
def trainModel(model, trainingSet, learningRate, epochs, numOutputs):
    for epoch in range(epochs):
        totalError = 0
        for inputVector in trainingSet:
            outputs = forwardPass(model, inputVector)
            expected = [0 for _ in range(numOutputs)]
            expected[inputVector[-1]] = 1  # Convert label to one-hot encoding
            totalError += sum([(expected[i] - outputs[i]) ** 2 for i in range(len(expected))])
            backwardPass(model, expected)
            adjustWeights(model, inputVector, learningRate)
        if epoch % 2 == 0:
            print(f"Epoch {epoch+1}/{epochs} | Learning Rate: {learningRate:.2f} | Error: {totalError:.6f}")
            print(f"Layer 1 Outputs: {model[0]['outputs']}")
            print(f"Layer 2 Outputs: {model[1]['outputs']}\n")

# Configuration and execution
inputNodes = 3
hiddenNodes = 3
outputNodes = 4
neuralNet = buildNetwork(inputNodes, hiddenNodes, outputNodes)

# Training dataset: last column is the label
trainingData =  [
    [0, 1, 0, 0],
    [1, 0, 0, 1],
    [0, 0, 1, 2],
    [1, 1, 0, 1]
]

trainModel(neuralNet, trainingData, learningRate=0.3, epochs=20, numOutputs=outputNodes)
