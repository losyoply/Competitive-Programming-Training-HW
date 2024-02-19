#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[200001]; //1~
int max_dist; 
int node_farthest; 

void dfs(int node, int parent, int dist) 
{
    if (dist > max_dist) 
    {
        max_dist = dist;
        node_farthest = node;
    }

    for (int child : tree[node]) 
    {
        if (child != parent) 
        {
            dfs(child, node, dist + 1);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) 
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    max_dist = -1; 
    dfs(1, -1, 0); // 節點1開始第一次DFS

    max_dist = -1; 
    dfs(node_farthest, -1, 0); // 最遠節點開始第二次DFS

    cout << max_dist; // 輸出樹的直徑
    return 0;
}
