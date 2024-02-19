#include <bits/stdc++.h>//hard
typedef long long ll;
using namespace std;

int n;
vector<int> graph[200001];
ll dp[200001], ans[200001];

void dfs1(int node = 1, int parent = 0, ll depth = 0) 
{
	ans[1] += depth;
	dp[node] = 1;
	for (int i : graph[node])
		if (i != parent) 
        {
			dfs1(i, node, depth + 1);
			dp[node] += dp[i];      //dp[node] 存儲從節點 node 開始的子樹中節點的數量。
		}
}

// 這是第二次深度優先搜索，用於根據 dfs1 的結果計算當每個其他節點作為根時的答案。
// ans[i] 被計算為 ans[node] + n - 2 * dp[i]。這裡，ans[node] 是父節點的答案，n - 2 * dp[i] 是調整項，用於從父節點的答案轉換到當前節點的答案。
void dfs2(int node = 1, int parent = 0) 
{
	for (int i : graph[node])
		if (i != parent) 
        {
			ans[i] = ans[node] + n - 2 * dp[i];
			dfs2(i, node);
		}
}
// 對於節點 i 的子樹中的節點：當根節點從 node 變為 i 時，這些節點到根節點的距離都減少了 1。子樹中有 dp[i] 個節點，因此總距離減少了 dp[i]。

// 對於節點 i 的子樹之外的節點：這些節點到新根節點 i 的距離都增加了 1。樹總共有 n 個節點，子樹中有 dp[i] 個節點，所以子樹之外有 n - dp[i] 個節點。
// 因此，對於這些節點，總距離增加了 n - dp[i]。
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) 
    {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1();
	dfs2();
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}