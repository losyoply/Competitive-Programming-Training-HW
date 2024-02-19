#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));
    for (int j = 1; j <= N; ++j) dp[0][j] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (A[i-1] == -1 || A[i-1] == j) {
                for (int k = 1; k <= N; ++k) {
                    if (k != j) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
    }

    long long result = 0;
    for (int j = 1; j <= N; ++j) {
        result += dp[N][j];
        result %= MOD;
    }

    cout << result << endl;
    return 0;
}
