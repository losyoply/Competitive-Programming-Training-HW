#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include<algorithm>
using namespace std;
bool isAdjacent(char a, char b) {
    unordered_map<char, vector<char>> adjacency = {
        {'A', {'E', 'B'}},
        {'B', {'A', 'C'}},
        {'C', {'B', 'D'}},
        {'D', {'C', 'E'}},
        {'E', {'D', 'A'}}
    };
    return find(adjacency[a].begin(), adjacency[a].end(), b) != adjacency[a].end();
}

int main() {
    char S1, S2, T1, T2;
    cin >> S1 >> S2 >> T1 >> T2;
    
 
    bool S_adjacent = isAdjacent(S1, S2);
    bool T_adjacent = isAdjacent(T1, T2);
    
    if (S_adjacent == T_adjacent) { // 兩者都是相鄰或都是非相鄰
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
