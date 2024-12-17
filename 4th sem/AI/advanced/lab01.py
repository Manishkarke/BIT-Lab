import random

class WumpusWorld:
    def __init__(self, size = 4):
        self.size = size
        self.grid = [["empty" for _ in range(size)] for _ in range(size)]
        self.agentPosition = (0,0)
        self.placeEntities()
        print("Environment Initialized")
        self.printWorld();
        
    def placeEntities(self):
        '''Place WUMPUS, GOLD, and PITs randomly'''
        self.placeRandom("wumpus")
        for _ in range(random.randint(1, 3)):
            self.placeRandom("pit")
        self.placeRandom("gold")
    
    def placeRandom(self, entity):
        while True:
            x, y = random.randint(0, self.size - 1), random.randint(0, self.size - 1)
            if((x,y) != (0, 0) and self.grid[x][y] == "empty"):
                self.grid[x][y] = entity
                break
    
    def percept(self):
        """Return percepts at agent's position."""
        x,y = self.agentPosition
        percepts = []
        if(any(self.grid[nx][ny] ) == "wumpus" for nx, ny in self.getNeighbour(x, y)):
            percepts.append("stench")
        
        if(any(self.grid[nx][ny]) == "gold" for nx, ny in self.getNeighbour(x, y)):
            percepts.append("glitter")
            
        if(any(self.grid[nx][ny]) == "pit" for nx, ny in self.getNeighbour(x, y)):
            percepts.append("breeze")
        
        return percepts
    
    '''Returns the Neighbour of the agent from the given position'''
    def getNeighbour(self, x, y):
        moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        return [(x + dx, y + dy) for dx, dy in moves if 0 <= x + dx < self.size and 0 <= y + dy < self.size]
    
    def moveAgent(self, direction):
        x, y = self.agentPosition
        moves = { "up": (-1,0), "down": (1, 0), "right": (0, 1), "left": (0, -1)}
        dx, dy = moves[direction]
        
        newX, newY = x + dx, y + dy
        
        if(0 <= newX < self.size and 0 <= newY < self.size):
            self.agentPosition = (newX, newY)
        print(f"Agent moved {direction} to {self.agentPosition}")
    ''' Print the Wumpus World '''
    def printWorld(self):
        for i in range(self.size):
            for j in range(self.size):
                if((i,j) == self.agentPosition):
                    print("A", end=" ")
                elif(self.grid[i][j] == "empty"):
                    print("_", end=" ")
                else:
                    print(self.grid[i][j][0], end=" ")
            print()
# -------- Base of Every Agents
class BaseAgent:
    def __init__(self, environment):
        self.environment = environment

    def moveRandomly(self):
        direction = random.choice(["UP", "DOWN", "LEFT", "RIGHT"])
        self.environment.moveAgent(direction)

# ----------- Simple Reflex Agent
class SimpleReflexAgent(BaseAgent):
    def act(self):
        percepts = self.environment.percept()
        print("\npercepts: ", percepts)
        
        if("glitter" in percepts):
            print("Found a gold.");
            return False
        if( "stench" in percepts or "breeze" in percepts):
            print("Danger ahead! moving randomly away")
            self.moveRandomly()
            
        else:
            print("Safe! Moving randomly")
            self.moveRandomly()
        return True
    
# -------------- Goal-Based Agent
class GoalBasedAgent(BaseAgent):
    def act(self):
        percepts = self.environment.percept()
        print("\nPercepts: ", percepts)
        
        if("glitter" in percepts):
            print("Goad achieved!! found gold")
            return False
        
        self.moveRandomly()
        return True
    
    
# ---------- Utility based agent
class UtilityBasedAgent(BaseAgent):
    def utility(self, percepts):
        if("glitter" in percepts):
            return 100
        if("breeze" in percepts):
            return -50
        
        return 0
    
    def act(self):
        percepts=self.environment.percept()
        print("\nPercepts: ", percepts)
        utilityV = self.utility(percepts)
        print(f"Utility: {utilityV}")
        
        if(utilityV == 100):
            print("Utility maximized!!! gold found")
            return False
        self.moveRandomly()
        return True
    

# -------- Simple Reflex Agents
print("\n--- Simple Reflex Agent ---")
environment = WumpusWorld()
agent = SimpleReflexAgent(environment)
while agent.act():
    pass

# ------- Goal Based Agent
print("\n---------- Goal-based Agent -------------")
environment = WumpusWorld()
agent = GoalBasedAgent(environment)
while agent.act():
    pass

# ---------- Utility Based agent
print("\n---------- Utility-based Agent -------------")
environment = WumpusWorld()
agent = UtilityBasedAgent(environment)
while agent.act():
    pass