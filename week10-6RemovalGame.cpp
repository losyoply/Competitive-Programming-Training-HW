#include <iostream>//hard
#include <cstring>
using namespace std;
  
int n, a[5005];
long long dp[5005][5005], pre[5005];
// dp[l][r] 表示当序列剩下的部分为从索引 l 到 r 时，当前玩家能获得的最大分数。
// pre[i] 存储了序列中从开始到索引 i 的所有元素的和。
long long f(int l, int r)
{
    if (dp[l][r] != -1) return dp[l][r];
    if (r-l <= 1) return dp[l][r] = max(a[l], a[r]);
    dp[l][r] = a[l] + pre[r] - pre[l] - f(l+1, r);
    //当玩家选择左端的数字后，他的分数会加上 a[l]。接下来，对手将在剩下的序列 [l+1, r] 中进行选择。
    //f(l+1, r) 是对手在序列 [l+1, r] 中能获得的最大分数
    dp[l][r] = max(dp[l][r], pre[r-1] - pre[l-1] - f(l, r-1) + a[r]);
    return dp[l][r];
}
  
int main() 
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }
    cout << f(1, n);
}