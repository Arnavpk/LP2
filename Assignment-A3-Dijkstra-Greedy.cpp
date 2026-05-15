#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], dist[MAX], visited[MAX], start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    for(int i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for(int count = 1; count < n; count++) {
        int min = INF, u;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest distances from vertex " << start << ":\n";
    for(int i = 0; i < n; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    return 0;
}