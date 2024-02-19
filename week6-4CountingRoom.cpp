#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>> &map, vector<vector<bool>> &visited) {
    if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size() || map[x][y] == '#' || visited[x][y])
        return;
    visited[x][y] = true;
    dfs(x + 1, y, map, visited);
    dfs(x - 1, y, map, visited);
    dfs(x, y + 1, map, visited);
    dfs(x, y - 1, map, visited);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    
    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, map, visited);
                ++rooms;
            }
        }
    }
    
    cout << rooms << endl;
    return 0;
}
