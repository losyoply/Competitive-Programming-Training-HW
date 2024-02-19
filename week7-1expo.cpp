#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int N;
ll A, B, C;

ll fastpow(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b > 0)
    {
        if(b&1) res = (res * a) % mod;
        //当指数为奇数时，我们需要额外乘上一个 a。
        a = (a * a) % mod;
        b=b/2;
    }
    return res;
}

int main()
{
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld", &A, &B, &C);
        printf("%lld\n", fastpow(A, fastpow(B, C, MOD-1), MOD));
    }
}