#include <iostream>
#include <vector>

using namespace std;

const int N = 8;
char board[N][N];
int solutions = 0;

bool is_safe(int row, int col) {
    for (int i = 0; i < col; i++) 
    {
        if (board[row][i] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) 
    {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solve(int col) {
    if (col == N) 
    {
        solutions++;
        return;
    }
    for (int i = 0; i < N; i++) 
    {
        if (board[i][col] == '.' && is_safe(i, col)) 
        {
            board[i][col] = 'Q';
            solve(col + 1);
            board[i][col] = '.';
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    solve(0);
    cout << solutions << endl;

    return 0;
}
