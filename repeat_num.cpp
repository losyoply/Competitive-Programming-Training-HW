

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findNumbersAppearedTwice(const std::vector<int>& a) {
    unordered_map<int, int> numCounts;

    for (int num : a) {
        if (numCounts.find(num) != numCounts.end()) {
            numCounts[num]++;
        } else {
            numCounts[num] = 1;
        }
    }


    for (const auto& pair : numCounts) {
        if (pair.second == 2) {
            return pair.first;
        }
    }

}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = findNumbersAppearedTwice(a);

    
    cout << result << endl;

    return 0;
}

