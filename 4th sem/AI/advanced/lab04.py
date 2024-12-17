class BlockWorld:
    def __init__(self, blocks, goalState):
        self.blocks = blocks
        self.goalState = goalState
    
    # Get Neighbour Blocks
    def getNeighbour(self, state):
        neighbours = []
        for i in range(len(state)):
            for j in range(i+1, len(state)):
                newState = state[:]
                newState[i], newState[j] = newState[j], newState[i]
                neighbours.append(newState)
        return neighbours
        
    # Get the heuristic value of a State
    def calculateHeuristic(self, state):
        score = 0
        for i in range(len(state)):
            if state[i] == self.goalState[i]:
                score += i + 1
            else:
                score -= i + 1
        return score

    # Hill climbing search
    def hillClimbing(self):
        currentState = self.blocks
        currentScore = self.calculateHeuristic(currentState)
            
        print(f"Initial State: {currentState}\ninitial score: {currentScore}")
            
        while currentScore < self.calculateHeuristic(self.goalState):
            neighbours = self.getNeighbour(currentState)
            nextState = None
            nextScore = currentScore
                
            for neighbour in neighbours:
                neighbourScore = self.calculateHeuristic(neighbour)
                if neighbourScore > nextScore:
                    nextState = neighbour
                    nextScore = neighbourScore
                        
            if nextState is None:
                print(f"Stuck in local optimum.")
                break
                
            currentState = nextState
            currentScore = nextScore
            
            print(f'\nCurrent state: {currentState}\nCurrent score: {currentScore}\n')
            
        return (currentState, currentScore)
            
initialState = ['A', 'H', 'G', "F", "E", "D", "C", "B"]
goalState = ['H', 'G', 'F', 'E', 'D', 'C', 'B', 'A']

blockWorld = BlockWorld(initialState, goalState)
solnState, solnScore = blockWorld.hillClimbing()

print(f"Final state: {solnState}\nFinal score: {solnScore}")