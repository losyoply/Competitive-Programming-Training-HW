#include <iostream>
#include <vector>

using namespace std;

int T;
int M, N;
int cantrow[15]={};
void printBoard(int board[][15], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;  // 換行到下一行
    }
}
bool isSafeR(int board[][15], int row, int col, int n) 
{
    int i, j;
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]==1) return false;
    }
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]==1) return false;
    }
    return true;
}
bool isSafeQ(int board[][15], int row, int col, int n) 
{
    int i, j;
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) return false;
    }

    return true;
}
long long factorial(int n) {
    long long res = 1;
    for(int i = 1; i <= n; i++) 
    {
        res *= i;
    }
    return res;
}

long long solveQR(int board[][15], int col, int n, int queensLeft,int rocksLeft)
{
    if (queensLeft == 0 && rocksLeft==0) 
    {
         return 1;
    }
    if(col==n) return 0;

    long long count0=0,count1 = 0;
    int flag=0;
    for (int i = 0; i < n; i++) 
    {
        if(cantrow[i]) continue;
        for(int q=0;q<2;q++)
        {
            if (q==0&&isSafeR(board, i, col, n)&&rocksLeft>=1) 
            {
                flag=1;
                board[i][col] = 2;
                cantrow[i]=1;
                count0 += solveQR(board, col + 1, n, queensLeft ,rocksLeft-1);
                cantrow[i]=0;
                board[i][col] = 0;
            }
            else if(q==1&&isSafeQ(board, i, col, n)&&queensLeft>=1)
            {
                flag=1;
                board[i][col] = 1;
                cantrow[i]=1;
                count1 += solveQR(board, col + 1, n, queensLeft - 1,rocksLeft);
                cantrow[i]=0;
                board[i][col] = 0;
            }
        }
    }
    if(flag==0) return 0;

    return count0+count1;
}
int main() {
    cin >> T;
    while (T--) 
    {
        cin >> M >> N;
        if (M == 0) //只有石頭
        {
            cout << factorial(N)  << endl;
        } 
        else if (N == 0) 
        {
            int board[15][15] = {0};
            cout << solveQR(board, 0, M , M,0) << endl;
        } 
        // else 
        // {
        //     int board[15][15] = {0};
        //     cout << solveQR(board, 0, M + N, M,N) << endl;
        // }
        else 
        {
            int board[15][15] = {0};
            cout<<solveQR(board, 0, M + N, M, N) <<endl;
        }
    }
    return 0;
}
