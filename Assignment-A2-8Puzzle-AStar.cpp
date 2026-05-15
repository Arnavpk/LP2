#include <iostream>
using namespace std;

#define N 3
#define MAX 100

struct Node {
    int mat[N][N];
    int x, y;
    int g, h, f;
};

int goal[N][N] = {
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

Node open[MAX];
int openSize = 0;

int closedCount = 0;

int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int calculateH(int mat[N][N]) {
    int count = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(mat[i][j] != 0 && mat[i][j] != goal[i][j])
                count++;
    return count;
}

int isGoal(int mat[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(mat[i][j] != goal[i][j])
                return 0;
    return 1;
}

void copyMat(int a[N][N], int b[N][N]) {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j] = b[i][j];
}

void addToOpen(Node n) {
    open[openSize++] = n;
}

Node getBestNode() {
    int idx = 0;
    for(int i=1;i<openSize;i++) {
        if(open[i].f < open[idx].f)
            idx = i;
    }
    Node best = open[idx];
    for(int i=idx;i<openSize-1;i++)
        open[i] = open[i+1];
    openSize--;
    return best;
}

void printMatrix(int mat[N][N]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void solve(int start[N][N], int x, int y) {
    Node startNode;
    copyMat(startNode.mat, start);
    startNode.x = x;
    startNode.y = y;
    startNode.g = 0;
    startNode.h = calculateH(start);
    startNode.f = startNode.g + startNode.h;

    addToOpen(startNode);

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(openSize > 0) {
        Node current = getBestNode();

        printMatrix(current.mat);

        if(isGoal(current.mat)) {
            cout << "Goal Reached\n";
            return;
        }

        for(int i=0;i<4;i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if(isSafe(nx, ny)) {
                Node child;
                copyMat(child.mat, current.mat);

                swap(child.mat[current.x][current.y], child.mat[nx][ny]);

                child.x = nx;
                child.y = ny;
                child.g = current.g + 1;
                child.h = calculateH(child.mat);
                child.f = child.g + child.h;

                addToOpen(child);
            }
        }
    }

    cout << "No Solution\n";
}

int main() {
    int start[N][N];
    int x, y;

    cout << "Enter 8-puzzle (0 for blank):\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> start[i][j];
            if(start[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    solve(start, x, y);

    return 0;
}