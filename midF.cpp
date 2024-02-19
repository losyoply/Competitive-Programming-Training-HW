#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's valid to place a bomb at (row, col)
bool isValidPlacement(vector<vector<int>>& matrix, int row, int col) {
    // Check the 3x3 grid centered at (row, col)
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size()) {
                if (matrix[newRow][newCol] <= 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Function to place a bomb at (row, col)
void placeBomb(vector<vector<int>>& matrix, int row, int col) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size()) {
                matrix[newRow][newCol]--;
            }
        }
    }
}

// Function to backtrack the placement of a bomb at (row, col)
void removeBomb(vector<vector<int>>& matrix, int row, int col) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size()) {
                matrix[newRow][newCol]++;
            }
        }
    }
}

// Recursive function to count the ways of placing bombs
void countWays(vector<vector<int>>& matrix, int row, int col, int& count) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Pruning: Check last row and last column conditions
    if (row == n - 1 && matrix[row][0] != 0) return;
    if (col == m - 1 && matrix[0][col] != 0) return;

    // If we reached the end of matrix, increment the count
    if (row == n) {
        count++;
        return;
    }

    // Calculate next position
    int nextRow = (col == m - 1) ? row + 1 : row;
    int nextCol = (col == m - 1) ? 0 : col + 1;

    // Try to place a bomb if it's valid
    if (isValidPlacement(matrix, row, col)) {
        placeBomb(matrix, row, col);
        countWays(matrix, nextRow, nextCol, count);
        removeBomb(matrix, row, col);
    }

    // Move to next cell without placing a bomb
    countWays(matrix, nextRow, nextCol, count);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    countWays(matrix, 0, 0, count);
    cout << count << endl;

    return 0;
}
