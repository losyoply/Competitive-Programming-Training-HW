#include <bits/stdc++.h>//h

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxN = 20;
const int INF = maxN+1;

int N;
pii dp[1<<maxN];
ll X, w[maxN];

int main(){
    cin>>N>>X;
    for(int i = 0; i < N; i++)
        cin>>w[i];

    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<N); mask++)
    {
        dp[mask] = {INF, 0};
        for(int i = 0; i < N; i++) //从0到2^N - 1的所有可能组合。
        {
            if(mask&(1<<i))
            {
                pii can = dp[mask^(1<<i)]; //从当前组合中移除物品i，获取没有该物品的组合的最优解。
                if(can.second + w[i] <= X)
                {
                    can.second += w[i];
                } 
                else 
                {
                    can.first++;
                    can.second = w[i];
                }
                dp[mask] = min(dp[mask], can);
            }
        }
    }

    cout<< dp[(1<<N)-1].first <<endl;
}