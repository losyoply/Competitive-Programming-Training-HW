#include <iostream>
#include <vector>
using namespace std;

void hanoi(int n, int from, int to, int aux, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({from, to});
        return;
    }
    // Move n-1 disks from 'from' to 'aux' using 'to' as auxiliary
    hanoi(n-1, from, aux, to, moves);
    // Move the nth disk from 'from' to 'to'
    moves.push_back({from, to});
    // Move n-1 disks from 'aux' to 'to' using 'from' as auxiliary
    hanoi(n-1, aux, to, from, moves);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> moves;
    hanoi(n, 1, 3, 2, moves);

    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
