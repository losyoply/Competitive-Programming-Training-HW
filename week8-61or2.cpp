#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;
int parent[MAX_N];

// 用於查找給定元素的根
int find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

// 將兩個元素的集合合併
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) 
    {
        parent[y] = x;
    }
}

int main() {
    int N, M, X, Y, Z;
    cin >> N >> M;

    // 初始化每個元素的根是其本身
    for (int i = 1; i <= N; ++i) 
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; ++i) 
    {
        cin >> X >> Y >> Z;
        unite(X, Y); // 將滿足條件的卡片合併
    }

    int cost = 0;
    for (int i = 1; i <= N; ++i) 
    {
        if (find(i) == i) 
        { // 如果元素是某個集合的根，則需要使用魔法
            cost++;
        }
    }

    cout << cost << endl;
    return 0;
}
