#include <iostream> //hard
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int editDistance(const string& str1, const string& str2) 
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // 初始化
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    //
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; //第i第j個字符是否依樣。
            dp[i][j] = min({
                dp[i - 1][j] + 1,    // Deletion
                dp[i][j - 1] + 1,    // Insertion
                dp[i - 1][j - 1] + cost  // Replacement or Match
            });
        }
    }

    return dp[n][m];
}

int main() 
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << editDistance(str1, str2) << endl;
    return 0;
}
