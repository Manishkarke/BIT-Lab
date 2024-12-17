X = [[0, 0], [0, 1], [1, 0], [1, 1]]
Y = [0, 0, 0, 1]

weights = [0, 0]
bias = 0
learningRate = 0.1
epochs = 100  # Number of training iteration

# For Hebbian Learning Rule
print("\n-------------- Hebbian Learning Rule -----------------")
def hebbianLearningRule():
    global weights, bias
    for epoch in range(epochs):
        for i in range(len(X)):
            output = 0
            linearOutput = X[i][0] * weights[0] + X[i][1] * weights[1] + bias
            output = 1 if linearOutput >= 0 else 0

            # Hebbian update: weight[j] += learningRate * X[i][j] * Y[i]
            for j in range(len(weights)):
                weights[j] += learningRate * X[i][j] * Y[i]

            # No update to bias in simple Hebbian learning rule
            # bias += learningRate * (Y[i] - output)  # This is not required for basic Hebbian learning

        if epoch % 10 == 0:
            print(f"\nEpoch {epoch}: Weights: {weights},\nBias: {bias}")

    print("\nTesting on All input Patterns:")
    for i in range(len(X)):
        output = 0
        if (X[i][0] * weights[0] + X[i][1] * weights[1] + bias) >= 0:
            output = 1
        print(f"Input: {X[i]} -> Predicted Output: {output}, Actual Output: {Y[i]}")

hebbianLearningRule()

# For Perceptron Rule
print("\n-------------- Perceptron Rule -----------------")
def perceptronRule():
    global weights, bias
    for epoch in range(epochs):
        for i in range(len(X)):
            output = 0
            linearOutput = X[i][0] * weights[0] + X[i][1] * weights[1] + bias
            output = 1 if linearOutput >= 0 else 0

            # Perceptron update: weight[j] += learningRate * X[i][j] * (Y[i] - output)
            for j in range(len(weights)):
                weights[j] += learningRate * X[i][j] * (Y[i] - output)

            # Update bias for perceptron
            bias += learningRate * (Y[i] - output)

        if epoch % 10 == 0:
            print(f"\nEpoch {epoch}: Weights: {weights},\nBias: {bias}")

    print("\nTesting on All input Patterns:")
    for i in range(len(X)):
        output = 0
        if (X[i][0] * weights[0] + X[i][1] * weights[1] + bias) >= 0:
            output = 1
        print(f"Input: {X[i]} -> Predicted Output: {output}, Actual Output: {Y[i]}")

perceptronRule()
