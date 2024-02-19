#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size;
int total_nodes;

int DFS(int node, int parent) 
{
    subtree_size[node] = 1;  
    for (int child : tree[node]) 
    {
        if (child != parent) 
        {  // Avoid going back to the parent
            subtree_size[node] += DFS(child, node);
        }
    }
    return subtree_size[node];
}

int findCentroid(int node, int parent) 
{
    for (int child : tree[node]) 
    {
        if (child != parent && subtree_size[child] > total_nodes / 2) 
        {
            return findCentroid(child, node);
        }
    }
    return node; 
}

int main() {
    int n;
    cin >> n;
    tree.resize(n + 1);
    subtree_size.resize(n + 1);
    total_nodes = n;

    for (int i = 1; i < n; ++i) 
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1, -1); 
    int centroid = findCentroid(1, -1); 
    cout << centroid << endl;

    return 0;
}
