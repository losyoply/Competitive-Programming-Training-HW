#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int main() {
    int Q, query_type, x;
    deque<int> A;
    bool is_sorted = true;

    cin >> Q; // number of queries

    for (int i = 0; i < Q; ++i) {
        cin >> query_type;

        switch (query_type) {
            case 1: // Append x to the end of A
                cin >> x;
                A.push_back(x);
                is_sorted = false;
                break;
            case 2: // Print and remove the smallest element in A
                cout << A.front() << endl;
                A.pop_front();
                break;
            case 3: // Sort A if it's not sorted
                if (!is_sorted) 
                {
                    sort(A.begin(), A.end());
                    is_sorted = true;
                }
                break;
        }
    }

    return 0;
}
