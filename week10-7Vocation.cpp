#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<vector<int>> happiness(N, vector<int>(3));
    for (int i = 0; i < N; ++i) 
    {
        cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];
    }


    vector<vector<int>> dp(N, vector<int>(3, 0));

    // 初始化
    dp[0][0] = happiness[0][0];
    dp[0][1] = happiness[0][1];
    dp[0][2] = happiness[0][2];

    for (int i = 1; i < N; ++i) 
    {
        dp[i][0] = happiness[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = happiness[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = happiness[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    
    int result = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});

    cout << result << endl;

    return 0;
}
