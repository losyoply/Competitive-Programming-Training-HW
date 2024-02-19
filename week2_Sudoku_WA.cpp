#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 9;

bool isValid(vector<vector<char>>& board, int row, int col, char c) 
{
    for (int i = 0; i < N; i++) 
    {
        if (board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (board[i][j] == '.') 
            {
                for (char c = '1'; c <= '9'; c++) 
                {
                    if (isValid(board, i, j, c)) 
                    {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    string line;
    while (getline(cin, line) && line != "end") {
        vector<vector<char>> board(N, vector<char>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = line[i * N + j];
        if (solveSudoku(board)) 
        {
            for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                {
                    cout << board[i][j];
                }
            }
            cout << endl;
        } 
        else 
        {
            cout << "No solution." << endl;
        }
    }
    return 0;
}
