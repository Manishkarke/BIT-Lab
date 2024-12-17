# 8-Puzzle problem
from collections import deque
class Puzzle:
    def __init__(self, initial, goal):
        self.initialState = initial
        self.goalState = goal
        self.directions = {
            "Up": (-1, 0),
            "Down": (1, 0),
            "Left": (0,-1),
            "Right": (0, 1)
        }
        
    # ----- Print the matrix
    @staticmethod
    def print(m):
        """ Print the Matrix """
        for i in range(3):
            for j in range(3):
                if(m[i][j] == 0):
                    print("_ ", end=" ")
                else:
                    print(f"{m[i][j]} ", end=" ")
            print()
            
    # --------- Check if the state is goal state
    def isGoal(self, state):
        return state == self.goalState
    
    # --------- Get position of blank 
    def getBlankPosition(self, matrix):
        for i in range(3):
            for j in range(3):
                if(matrix[i][j] == 0):
                    return (i,j)
        return None
    
    # ------ Swap position of elements
    def swapPosition(matrix, p1, p2):
        matrixCopy = [row[:] for row in matrix]
        matrixCopy[p1[0]][p1[1]], matrixCopy[p2[0]][p2[1]] = matrixCopy[p2[0]][p2[1]], matrixCopy[p1[0]][p1[1]]
        return matrixCopy
    
    # --------- Get Neighbour nodes
    def getNeighbours(self, matrix):
        neighbours = []
        blankPos = self.getBlankPosition(matrix)
        row, col = blankPos
    
        for direction, (dr, dc) in self.directions.items():
            newRow, newCol = row + dr, col + dc
        
            if( 0 <= newRow < 3 and 0 <= newCol < 3):
                matrixCopy = [row[:] for row in matrix]
                matrixCopy[row][col], matrixCopy[newRow][newCol] = matrixCopy[newRow][newCol], matrixCopy[row][col]
                neighbours.append((matrixCopy, direction))
            
        return neighbours
    
    # BFS solution
    def bfs(self):
    
        visited = set()
        queue = deque([(self.initialState, [], 0)])  # Current state, path, level
    
        while queue:
            currentState, path, level = queue.popleft()
            
            """ The Below code is to print every code at their level """
            # print("\nCurrent State at Level", level)
            # Puzzle.print(currentState)
            
            if self.isGoal(currentState):
                print("\nGoal Reached!")
                print(f"Steps to Goal ({level} moves):")
                for step, move in enumerate(path):
                    print(f"Step {step+1}: Move {move}")
                return True
        
            stateTuple = tuple(map(tuple, currentState))
            if stateTuple in visited:
                continue
            
            if stateTuple not in visited:
                # print("Visiting State:", stateTuple)
                visited.add(stateTuple)
                for neighbour, direction in self.getNeighbours(currentState):
                    queue.append((neighbour, path + [direction], level + 1))
    
        print("No solution found!")
        return False
    
    # -------- DFS solution
    def dfs(self):
        visited = set()
        stack = [(self.initialState, [], 0)]
        
        while stack:
            currentState, path, level = stack.pop()
            
            if self.isGoal(currentState):
                print(f"Goal reached at level {level}")
                print("Steps to reach goal: ")
                for step, move in enumerate(path):
                    print(f"Step {step+1}: Move {move}")
                return True
            
            stateTuple = tuple(map(tuple, currentState))
            if stateTuple in visited:
                continue
            else:
                visited.add(stateTuple)
                for neighbour, direction in reversed(self.getNeighbours(currentState)):
                    stack.append((neighbour, path + [direction], level + 1))
            
        print("No solution found!")
        return False
    
    # ------ Iterative Deepening Depth first Search 
    def iddfs(self):
        
        def dls(state, path, level, depth):
            if(self.isGoal(state)):
                print(f"Goal reached at level {level}")
                print("Steps to reach goal: ")
                for step, move in enumerate(path):
                    print(f"Step {step+1}: Move {move}")
                return True
            
            if level == depth:
                return False
            
            for neighbour, direction in self.getNeighbours(state):
                if(dls(neighbour, path + [direction], level + 1, depth)):
                    return True
            
            return False
        
        depth = 0
        
        while True:
            print(f"Depth limit: {depth}")
            if(dls(self.initialState, [], 0, depth)):
                return True
            
            depth += 1
                
            
initialState = [[1, 2, 3],
                [8, 0, 4],
                [7, 6, 5]]

goalState = [[2, 8, 1],
             [0, 4, 3],
             [7, 6, 5]]

puzzle = Puzzle(initialState, goalState)

print("Initial State:")
Puzzle.print(puzzle.initialState)
print("\nGoal State:")
Puzzle.print(puzzle.goalState)

# -------- Solving using BFS
print("\n\nSolving 8 Puzzle problem using BFS")
puzzle.bfs()

# -------- Solving using dfs
# print("\n\nSolving 8 puzzle problem using DFS")
# puzzle.dfs()

# -------- Solving using iddfs
print("\n\nSolving 8 puzzle problem using IDDFS")
puzzle.iddfs()
