#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the speed of Tian's horses after M days
int calc_speed_after_days(int speed, int growth, int days) {
    return speed + growth * days;
}

int min_days_to_win(int N, int K, const vector<pair<int, int>>& tian_horses, const vector<int>& enemy_horses) {
    // Start from day 0 and increase to find the minimum days needed
    for (int M = 0; M < 10000; ++M) { // Arbitrary large number to prevent infinite loop
        vector<int> tian_current_speeds;
        for (const auto& horse : tian_horses) {
            tian_current_speeds.push_back(calc_speed_after_days(horse.first, horse.second, M));
        }
        sort(tian_current_speeds.rbegin(), tian_current_speeds.rend());
        vector<int> enemy_sorted(enemy_horses);
        sort(enemy_sorted.rbegin(), enemy_sorted.rend());

        int wins = 0, ti = 0, ei = 0;
        // Compare the sorted speeds to find the number of wins
        while (ti < N && ei < N) {
            if (tian_current_speeds[ti] > enemy_sorted[ei]) {
                wins++;
                ti++;
                ei++;
            } else {
                ei++;
            }
        }

        if (wins >= K) return M; // If wins are enough, return the days
    }
    return -1; // If it's not possible to win, return -1
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> tian_horses(N);
        vector<int> enemy_horses(N);

        for (int i = 0; i < N; ++i) {
            cin >> tian_horses[i].first >> tian_horses[i].second;
        }
        for (int i = 0; i < N; ++i) {
            cin >> enemy_horses[i];
        }

        // Sort Tian's horses by potential (growth rate then speed)
        sort(tian_horses.begin(), tian_horses.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second > b.second;
        });

        cout << min_days_to_win(N, K, tian_horses, enemy_horses) << endl;
    }
    return 0;
}