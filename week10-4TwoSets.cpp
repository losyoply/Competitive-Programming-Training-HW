#include <iostream>
using namespace std;
  
int n, dp[505][63000], mod = 1e9+7;
  
int main() 
{
    cin >> n;
    //
    int tar = n * (n+1) / 2;
    if (tar % 2) 
    {
        cout << 0;
        return 0;
    }
    tar /= 2;
    //
    dp[0][0] = 1;//
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            dp[i][j] += dp[i-1][j];//不選擇當前的數字i
            dp[i][j] %= mod;
            if (j >= i)//如果j小於i，則無法選擇當前數字，因為我們不能有負數的和。
            {
                dp[i][j] += dp[i-1][j-i];//選擇了數字i後新的和為j的方法數。
                dp[i][j] %= mod;
            }
        }
    }
    //每一種分割都被計算了兩次（一次為一個子集，另一次為另一個子集的補集），所以需要將結果除以2。
    //在模數運算中，這相當於乘以2的模逆元，
    //這裡是500000004，因為 
    long long ans = dp[n][tar];
    ans *= 500000004;
    ans %= mod;
    cout << ans << "\n";
}