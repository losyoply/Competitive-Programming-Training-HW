#include <iostream>
#include <vector>
using namespace std;
long long minSplits(const vector<int>& A, int S) {
    long long count = 0;
    int sum = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (sum + A[i] > S) {
            count++; 
            sum = 0;
        }
        sum += A[i];
    }
    return count + (sum > 0 ? 1 : 0); 
}

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long result = 0;
    for (int l = 0; l < N; ++l) {
        for (int r = l; r < N; ++r) {
            result += minSplits(vector<int>(A.begin() + l, A.begin() + r + 1), S);
        }
    }

    cout << result << endl;
    return 0;
}
