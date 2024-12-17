class Node:
    def __init__(self, name, parent = None, g=0, h=0):
        self.name = name
        self.parent = parent
        self.g = g
        self.h = h
        self.f = g + h
        
    
# Best First Search Algorithm
def bestFirstSearch(graph, start, goal, heuristic):
    openList = []
    visited = set()
    
    startNode = Node(start, h=heuristic[start])
    openList.append(startNode)
    
    while openList:
        currentNode = min(openList, key=lambda node: node.h)
        openList.remove(currentNode)
        
        if currentNode.name == goal:
            path = []
            while currentNode:
                path.append(currentNode.name)
                currentNode = currentNode.parent
            return path[::-1]
        
        visited.add(currentNode.name)
        
        for neighbour in graph[currentNode.name]:
            if neighbour in visited:
                continue
            
            neighbourNode = Node(neighbour, currentNode, h=heuristic[neighbour])
            openList.append(neighbourNode)
    
    return None

# A* Search
def aStarSearch(graph, start, goal, heuristic, cost):
    openList = []
    visited = set()
    
    startNode = Node(start, g=0, h=heuristic[start])
    openList.append(startNode)
    
    while openList:
        currentNode = min(openList, key=lambda node: node.f)
        openList.remove(currentNode)
        
        if currentNode.name == goal:
            path = []
            
            while currentNode:
                path.append(currentNode.name)
                currentNode = currentNode.parent
                
            return path[::-1]
        visited.add(currentNode.name)
    
        for neighbour in graph[currentNode.name]:
            if neighbour in visited:
                continue
        
            gCost = currentNode.g + cost[(currentNode.name, neighbour)]
            neighbourNode = Node(neighbour, currentNode, g=gCost, h=heuristic[neighbour]) 
            openList.append(neighbourNode)
    
    return None


# Define the graph
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# heuristic values (h)
heuristic = {
    'A': 6,
    'B': 4,
    'C': 2,
    'D': 3,
    'E': 1,
    'F': 0 
}

# cost between nodes (g)
cost = {
    ('A', 'B'): 1,
    ('A', 'C'): 2,
    ('B', 'A'): 1,
    ('B', 'D'): 3,
    ('B', 'E'): 1,
    ('C', 'A'): 2,
    ('C', 'F'): 3,
    ('D', 'B'): 3,
    ('E', 'B'): 1,
    ('E', 'F'): 2,
    ('F', 'C'): 3,
    ('F', 'E'): 2
}

start = 'A'
goal = 'F'

# Greedy Best First Search
bestFirstPath = bestFirstSearch(graph, start, goal, heuristic)
print("Best First Search Path:", bestFirstPath)

# A* Search
aStarPath = aStarSearch(graph, start, goal, heuristic, cost)
print("A* Search Path:", aStarPath)