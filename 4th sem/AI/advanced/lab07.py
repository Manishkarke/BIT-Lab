import random

# Generate an individual (random chromosome)
def generateIndividual(length):
    return [random.randint(0, 1) for _ in range(length)]

# Create a population of individuals
def populationGenerator(size, length):
    return [generateIndividual(length) for _ in range(size)]

# Fitness function: sum of 1s in the chromosome
def fitnessFunction(individual):
    return sum(individual)

# Tournament selection for choosing parents
def tournamentSelection(population, tournamentSize):
    selectedParents = random.sample(population, tournamentSize)
    selectedParents.sort(key=fitnessFunction, reverse=True)
    return selectedParents[0], selectedParents[1]

# Crossover (Single-point crossover)
def crossover(parent1, parent2, crossoverPoint):
    child1 = parent1[:crossoverPoint] + parent2[crossoverPoint:]
    child2 = parent2[:crossoverPoint] + parent1[crossoverPoint:]
    return child1, child2

# Mutation (Random bit flip)
def mutation(individual, mutationRate):
    return [1 - gene if random.random() < mutationRate else gene for gene in individual]

# Main genetic algorithm function
def geneticAlgorithm(populationSize, chromosomeLength, generations, mutationRate, tournamentSize):
    population = populationGenerator(populationSize, chromosomeLength)
    bestIndividual = None
    bestFitness = 0
    
    for generation in range(generations):
        # Evaluate fitness of the entire population
        fitnesses = [fitnessFunction(individual) for individual in population]
        
        # Update the best individual found so far
        currentBestFitness = max(fitnesses)
        if currentBestFitness > bestFitness:
            bestFitness = currentBestFitness
            bestIndividual = population[fitnesses.index(bestFitness)]

        # Generate new population using selection, crossover, and mutation
        newPopulation = []
        for _ in range(populationSize // 2):
            # Select parents using tournament selection
            parent1, parent2 = tournamentSelection(population, tournamentSize)
            
            # Perform crossover to produce offspring
            crossoverPoint = random.randint(1, chromosomeLength - 1)
            child1, child2 = crossover(parent1, parent2, crossoverPoint)
            
            # Apply mutation to the children
            child1 = mutation(child1, mutationRate)
            child2 = mutation(child2, mutationRate)
            
            newPopulation.extend([child1, child2])

        # Replace old population with new population
        population = newPopulation

    return bestIndividual, bestFitness

# Parameters
populationSize = 50
chromosomeLength = 20
generations = 100
mutationRate = 0.01
tournamentSize = 5  # Tournament selection size

bestIndividual, bestFitness = geneticAlgorithm(populationSize, chromosomeLength, generations, mutationRate, tournamentSize)

print("Best Individual:", bestIndividual)
print("Best Fitness:", bestFitness)
