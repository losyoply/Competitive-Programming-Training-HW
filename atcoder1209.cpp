#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N; 

    vector<long long> A(N + 1), P(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i]; 
    }
    for (int i = 2; i <= N; ++i) {
        cin >> P[i]; 
    }

    
    long long delta = 0;
    bool hasCycle = false;
    vector<long long> seen(N + 1, 0);
    long long operations = 0;

    while (!hasCycle && operations < N) {
        operations++;
        for (int i = 2; i <= N; ++i) {
            A[i] += A[P[i]];
            if (P[i] == 1) {
                delta += A[i];
            }
            if (seen[i] == A[i]) {
                hasCycle = true;
                break;
            }
            seen[i] = A[i];
        }
    }

    if (delta < 0) {
        cout << "-";
    } else if (delta > 0) {
        cout << "+";
    } else {
        cout << "0";
    }

    return 0;
}
