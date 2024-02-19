//拓扑排序
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, a, b, cnt, in[maxN];
vector<int> ans, G[maxN];
queue<int> Q;
// N 和 M 分别代表图中的顶点数和边数。
// cnt 用于追踪还未加入拓扑排序的顶点数量。
// in （指向该顶点的边数）。
// ans 是一个向量，用于存储最终的拓扑排序。
// G 是一个向量数组，用于表示图（每个顶点的邻接表）。
// Q 是一个队列，用于执行拓扑排序的BFS（广度优先搜索）。
int main()
{
    cin>>N>>M;
    for(int i = 0; i < M; i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        in[b]++;
    }

    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    cnt = N;
    while(!Q.empty())
    {
        int u = Q.front(); 
        Q.pop();
        ans.push_back(u);
        cnt--;

        for(int v : G[u])
        {
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    if(cnt)
        printf("IMPOSSIBLE\n");
    else
        for(int i = 0; i < N; i++)
            printf("%d%c", ans[i], (" \n")[i==N-1]);
}