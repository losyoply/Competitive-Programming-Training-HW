#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int N;
    cin >> N;
    
    vector<long> reunits;
    long a=1;
    for (int x = 0; x < 12; x++) {
        reunits.push_back(a);
        a = a * 10 + 1;
    }
    
    set<long> unique_sums;
    for (int i = 0; i < reunits.size(); ++i) {
        for (int j = 0; j < reunits.size(); ++j) {
            for (int k = 0; k < reunits.size(); ++k) {

                long sum = reunits[i] + reunits[j] + reunits[k];
                unique_sums.insert(sum);
            }
        }
    }
    
    
    vector<long> sorted_sums(unique_sums.begin(), unique_sums.end());
    // cout<<sorted_sums.size();
    if (N-1 < sorted_sums.size()) {
        cout << sorted_sums[N-1] << endl;
    } 

    return 0;
}
