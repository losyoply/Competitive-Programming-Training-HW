#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function to generate all permutations of the string
void generatePermutations(string s, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            generatePermutations(s, l+1, r, result);
            swap(s[l], s[i]); // backtrack
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<string> permutations;
    generatePermutations(s, 0, s.length()-1, permutations);

    // Sort and remove duplicates
    sort(permutations.begin(), permutations.end());
    permutations.erase(unique(permutations.begin(), permutations.end()), permutations.end());

    cout << permutations.size() << endl;
    for (const string& str : permutations) {
        cout << str << endl;
    }

    return 0;
}
