#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(const vector<int>& arr, int index, vector<int>& current, int M) {
    if (current.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << current[i] << (i == M - 1 ? "\n" : " ");
        }
        return;
    }
    if (index == arr.size()) return;

    // Include the current element
    current.push_back(arr[index]);
    generateCombinations(arr, index + 1, current, M);

    // Exclude the current element
    current.pop_back();
    generateCombinations(arr, index + 1, current, M);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> current;
    generateCombinations(arr, 0, current, M);

    return 0;
}
