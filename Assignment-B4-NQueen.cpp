#include <iostream>
using namespace std;

#define MAX 10

int board[MAX];
bool col[MAX], d1[2*MAX], d2[2*MAX];
int n;

void printSolution() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int row) {
    if(row == n) {
        printSolution();
        return;
    }

    for(int j = 0; j < n; j++) {
        if(!col[j] && !d1[row - j + n - 1] && !d2[row + j]) {
            
            board[row] = j;
            col[j] = d1[row - j + n - 1] = d2[row + j] = true;

            solve(row + 1);

            col[j] = d1[row - j + n - 1] = d2[row + j] = false;
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    solve(0);

    return 0;
}