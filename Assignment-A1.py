# Assignment-A1: DFS & BFS

"""
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected graph and develop a recursive algorithm for searching all the vertices of a graph or tree data structure.

Code from ArtificialIntelligence (SPPU - Third Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-te-comp-content/ArtificialIntelligence
"""

# BEGINNING OF CODE
from collections import deque

class Graph:
    # Constructor to initalize an empty dictionary
    def __init__(self):
        self.graph = {}

    # Add edges
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
        self.graph[u].append(v)
        self.graph[v].append(u)  # Since the graph is undirected; Comment this line if graph is directed.

    # Perform Depth First Search (DFS)
    def dfs(self, start, visited=None):
        if visited is None:
            visited = set()

        visited.add(start)
        print(start, end=" ")

        for neighbour in self.graph.get(start, []):
            if neighbour not in visited:
                self.dfs(neighbour, visited)

    # Perform Breadth First Search (BFS)
    def bfs(self, start):
        visited = set()
        visited.add(start)
        queue = deque([start])

        def bfs_helper():
            if not queue:
                return

            vertex = queue.popleft()
            print(vertex, end=" ")

            for neighbour in self.graph.get(vertex, []):
                if neighbour not in visited:
                    visited.add(neighbour)
                    queue.append(neighbour)
            bfs_helper()

        bfs_helper()

def main():
    g = Graph()

    while True:
        print("\n\n", "-"*10, "MAIN MENU", "-"*10)
        print("1. Add edge")
        print("2. Depth First Search (DFS)")
        print("3. Breadth First Search (BFS)")
        print("4. Exit")
        choice = int(input("Choose an option (1-4):\t"))
        print("-"*32)

        if choice == 1:
            total = int(input("\nTotal edges to add:\t"))
            for i in range(total):
              print(f"EDGE {i+1} ->")
              u = input(f"Enter first vertex for edge {i+1}: ")
              v = input(f"Enter second vertex for edge {i+1}: ")
              g.add_edge(u, v)
            print("\nVertices and its neighbours are:\t", g.graph)
        elif choice == 2:
            start = input("\nEnter starting vertex for DFS:\t")
            print("Depth First Search (DFS):\t")
            g.dfs(start)
        elif choice == 3:
            start = input("\nEnter starting vertex for BFS:\t")
            print("Breadth First Search (BFS):\t")
            g.bfs(start)
        elif choice == 4:
            print("\n## END OF CODE\n")
            break
        else:
            print("\nPlease choose a valid option.")

main()
# END OF CODE
