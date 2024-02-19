#include <bits/stdc++.h>//hard

using namespace std;

// dist[0][i] = distance from node a to node i
// dist[1][i] = distance from node b to node i
int dist[2][200000];
vector<int> adj[200000];

int dfs(int u, int p, int d, int i) 
{
	dist[i][u] = d;
	int opt = -1;
	for (int v : adj[u]) 
	{
		if (v != p) 
		{
			int x = dfs(v, u, d + 1, i);
			if (opt == -1 || dist[i][x] > dist[i][opt]) opt = x;
		}
	}
	
	return opt == -1 ? u : opt;
}
// u：當前正在訪問的節點。
// p：當前節點的父節點。這用於避免搜索回到已經訪問過的節點。
// d：從起點節點到當前節點 u 的距離。
// i：指示當前是從哪個節點開始的搜索，用於更新 dist 數組的哪一行。這個參數
int main() 
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) 
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// first, find node a by finding the farthest node from an arbitrary node x
	int mxNode = dfs(0, 0, 0, 0);
	// then, find node b (this step also computes distance from a to every other
	// node)
	int mxNode2 = dfs(mxNode, mxNode, 0, 0);
	// finally, compute the distance from b to every other node
	dfs(mxNode2, mxNode2, 0, 1);

	for (int i = 0; i < n; i++) cout << max(dist[0][i], dist[1][i]) << " \n"[i == n - 1];
	
	return 0;
}

// 對於樹中的任何節點，其到最遠節點的距離將是它到 mxNode 或 mxNode2 中較遠者的距離。這是因為在樹的結構中，
// 任何從一個節點到另一節點的路徑都必須經過直徑的一部分。
// 所以，最終對於每個節點，程式輸出它到這兩個節點中較遠者的距離，這也就是它到樹中另一節點的最大距離。