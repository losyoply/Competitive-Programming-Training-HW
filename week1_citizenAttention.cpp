#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f; // A common representation for "infinity" in integer context
vector<vector<int>> grid(5, vector<int>(5, 0));
vector<int> ch(5), ans(5);
int minv;

void dfs(int idx, int i) //i是選的值 idx選的第幾個
{
    if (idx == 5) 
    {
        int sum = 0, tmp;
        for (int i = 0; i < 5; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                if (grid[i][j]) 
                {
                    tmp = oo;
                    for (int k = 0; k < 5; k++) 
                    {
                        int x = ch[k] / 5, y = ch[k] % 5;
                        tmp = min(tmp, abs(x - i) + abs(y - j));
                    }
                    sum += grid[i][j] * tmp;
                }
            }
        }
        if (sum < minv) 
        {
            minv = sum;
            ans = ch;
        }
        return;
    }

    for (; i < 25; i++)  //i是選的值 idx選的第幾個 i只會往後選
    {
        ch[idx] = i;
        dfs(idx + 1, i + 1);
    }
}

int main() {
    int t, n, i, j, k;
    cin >> t;
    while (t--) 
    {
        cin >> n;
        grid.assign(5, vector<int>(5, 0));

        while (n--) 
        {
            cin >> i >> j >> k;
            grid[i][j] += k;
        }

        minv = oo;
        dfs(0, 0);

        for (int i = 0; i < 5; i++) 
        {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
