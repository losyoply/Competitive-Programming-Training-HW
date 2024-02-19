#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> scores(N); // 存儲每位學生前三天的總分
    vector<int> sortedScores(N); // 用於排序和確定前K名分數線
    int Pij;
    // 讀取學生分數
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> Pij;
            scores[i] += Pij; // 計算總分
        }
        sortedScores[i] = scores[i]; // 複製分數用於排序
    }

    // 排序以找出前K名分數線
    sort(sortedScores.begin(), sortedScores.end(), greater<int>());

    // 計算前K名的最低分數
    int cutoffScore = sortedScores[K - 1];

    // 檢查每位學生是否有可能進入前K名
    for (int i = 0; i < N; ++i) {
        if (scores[i] + 300 >= cutoffScore) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
