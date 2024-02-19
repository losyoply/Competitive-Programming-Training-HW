#include <bits/stdc++.h> //沒看懂

using namespace std;
typedef long long ll;
const int maxX = 1e6+1;

ll ans;
int N, dp[maxX];
bool b[maxX];
vector<int> primes;

void init()
{
    fill(b+2, b+maxX, true);
    for(int i = 2; i*i < maxX; i++)
        if(b[i])
            for(int j = i*i; j < maxX; j += i)
                b[j] = false;
    for(int i = 2; i < maxX; i++)
        if(b[i])
            primes.push_back(i);
}

void compute(int x)
{
    vector<int> pf;
    for(int p : primes)
    {
        if(x == 1)  break;
        else if(b[x])
        {
            pf.push_back(x);
            break;
        }

        if(x % p)   continue;

        pf.push_back(p);
        while(x % p == 0)
            x /= p;
    }

    int K = (int) pf.size();
    for(int mask = 0; mask < (1<<K); mask++)
    {
        int mu = 1;
        for(int i = 0; i < K; i++)
            if(mask&(1<<i))
                mu *= pf[i];

        int k = __builtin_popcount(mask);
        ans += (k&1 ? -dp[mu] : dp[mu]);
        dp[mu]++;
    }
}

int main()
{
    init();
    scanf("%d", &N);
    for(int i = 0, x; i < N; i++)
    {
        scanf("%d", &x);
        compute(x);
    }
    printf("%lld\n", ans);
}

// 计算每个数的质因数（compute函数）:

// 对于输入的每个数x，函数compute找出其所有的不同质因数并存储在向量pf中。
// 然后，它使用这些质因数的不同组合计算出每种组合对答案的贡献。
// 这里使用的是包含-排除原理，对于每个质因数组合，如果组合中的质数个数是奇数，它会从答案中减去dp[mu]（即包含该组合的数的数量），如果是偶数则加上dp[mu]。

// 在compute函数中，mu变量代表当前的质因数组合的乘积。__builtin_popcount(mask)是一个内置函数，返回mask中置位的数量（即二进制表示中1的个数）。
//dp[mu]数组在这里用于计算每个数的质因数组合的乘积出现的次数。通过改变组合中质数的数量，我们可以计算出每种可能组合的数对的数量，这种方法利用了包含-排除原理。
