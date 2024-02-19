#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].second >> tasks[i].first; // 最後期限/持續時間
    }

    // 根據持續時間對任務進行排序
    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    long long total_time = 0;
    long long reward = 0;

    for (auto task : tasks) {
        total_time += task.second; // 更新總時間
        reward += task.first - total_time; // 計算報酬並加到總報酬上
    }

    cout << reward << endl;

    return 0;
}
