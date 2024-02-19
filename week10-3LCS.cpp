#include <bits/stdc++.h>//hard

using namespace std;

string longestCommonSubsequence(string s, string t) 
{
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // 填充dp表
    for (int i = 1; i <= m; ++i) 
    {
        for (int j = 1; j <= n; ++j) 
        {
            if (s[i - 1] == t[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 從dp表的最右下角開始回溯，構造LCS
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (s[i - 1] == t[j - 1]) 
        {
            lcs.push_back(s[i - 1]);
            --i;
            --j;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
        {
            --i;
        } 
        else 
        {
            --j;
        }
    }

    // 因為我們是從後往前構造的，所以要將字符串反轉過來
    reverse(lcs.begin(), lcs.end());

    return lcs;
}

int main() 
{
    string s, t;
    cin >> s >> t;
    cout << longestCommonSubsequence(s, t) << endl;
    return 0;
}
