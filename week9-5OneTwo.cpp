#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> colors;
vector<vector<int>> adj;

bool dfs(int v, int c) 
{
    if (colors[v] != 0) 
    {
        return colors[v] == c;
    }
    
    colors[v] = c;
    for (int u : adj[v]) 
    {
        if (!dfs(u, c ^ 3)) 
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n);
    colors.resize(n, 0);
    
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        --u; --v; // Convert to zero-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool possible = true;
    for (int i = 0; i < n; i++) 
    {
        if (colors[i] == 0 && !dfs(i, 1)) 
        {
            possible = false;
            break;
        }
    }
    
    if (possible) 
    {
        for (int color : colors) 
        {
            cout << color << " ";
        }
        cout << endl;
    } 
    else 
    {
        cout << "MANY" << endl;
    }
    
    return 0;
}
