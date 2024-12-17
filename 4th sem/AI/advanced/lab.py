from collections import deque
import copy

class EightPuzzleSolver:
    def __init__(self, initial_state, goal_state):
        self.initial_state = initial_state
        self.goal_state = goal_state
        self.directions = {
            "Up": (-1, 0),
            "Down": (1, 0),
            "Left": (0, -1),
            "Right": (0, 1)
        }

    # Function to print a 3x3 matrix
    def print_matrix(self, matrix):
        for row in matrix:
            print(" ".join(str(x) if x != 0 else "_" for x in row))
        print()

    # Function to check if a state is the goal state
    def is_goal(self, state):
        return state == self.goal_state

    # Get blank position
    def get_blank_position(self, state):
        for i in range(3):
            for j in range(3):
                if state[i][j] == 0:
                    return i, j
        return None

    # Generate neighbors by swapping blank space
    def get_neighbors(self, state):
        neighbors = []
        row, col = self.get_blank_position(state)

        for direction, (dr, dc) in self.directions.items():
            new_row, new_col = row + dr, col + dc
            if 0 <= new_row < 3 and 0 <= new_col < 3:
                new_state = copy.deepcopy(state)
                new_state[row][col], new_state[new_row][new_col] = new_state[new_row][new_col], new_state[row][col]
                neighbors.append((new_state, direction))
        return neighbors

    # Breadth-First Search (BFS)
    def bfs(self):
        print("\n--- Solving with BFS ---")
        visited = set()
        queue = deque([(self.initial_state, [], 0)])  # (state, path, depth)

        while queue:
            state, path, depth = queue.popleft()
            state_tuple = tuple(map(tuple, state))  # Convert to tuple for hashability

            if state_tuple in visited:
                continue

            visited.add(state_tuple)

            if self.is_goal(state):
                print(f"Goal reached in {depth} moves using BFS!")
                return path

            for neighbor, direction in self.get_neighbors(state):
                queue.append((neighbor, path + [direction], depth + 1))

        return None

    # Depth-First Search (DFS) with depth limit
    def dfs(self, state, path, visited, depth, limit):
        if self.is_goal(state):
            return path

        if depth > limit:
            return None

        state_tuple = tuple(map(tuple, state))
        if state_tuple in visited:
            return None

        visited.add(state_tuple)

        for neighbor, direction in self.get_neighbors(state):
            result = self.dfs(neighbor, path + [direction], visited, depth + 1, limit)
            if result:
                return result

        return None

    # Iterative Deepening Depth-First Search (IDDFS)
    def iddfs(self):
        print("\n--- Solving with IDDFS ---")
        limit = 0
        while True:
            visited = set()
            result = self.dfs(self.initial_state, [], visited, 0, limit)
            if result:
                print(f"Goal reached at depth {limit} using IDDFS!")
                return result
            limit += 1

# Initial and Goal States
initial_state = [
    [1, 2, 3],
    [8, 0, 4],
    [7, 6, 5]
]

goal_state = [
    [1, 2, 3],
    [8, 0, 4],
    [7, 6, 5]
]

# Instantiate and Solve the Puzzle
solver = EightPuzzleSolver(initial_state, goal_state)

# Run BFS
bfs_solution = solver.bfs()
if bfs_solution:
    print("Solution path:", bfs_solution)

# Run IDDFS
iddfs_solution = solver.iddfs()
if iddfs_solution:
    print("Solution path:", iddfs_solution)
