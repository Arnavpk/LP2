#include <iostream>
using namespace std;

#define MAX 10

class Graph {
    int adj[MAX][MAX];
    int visited[MAX];
    int V;

public:
    void createGraph() {
        cout << "Enter number of vertices: ";
        cin >> V;

        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }

        int edges, u, v;
        cout << "Enter number of edges: ";
        cin >> edges;

        cout << "Enter edges (u v):\n";
        for (int i = 0; i < edges; i++) {
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    void DFS(int v) {
        cout << v << " ";
        visited[v] = 1;

        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                DFS(i);
            }
        }
    }

    void BFS(int start) {
        int queue[MAX], front = 0, rear = 0;

        for (int i = 0; i < V; i++) {
            visited[i] = 0;
        }

        visited[start] = 1;
        queue[rear++] = start;

        while (front < rear) {
            int v = queue[front++];
            cout << v << " ";

            for (int i = 0; i < V; i++) {
                if (adj[v][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.createGraph();

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    g.DFS(start);

    cout << "\nBFS Traversal: ";
    g.BFS(start);

    return 0;
}