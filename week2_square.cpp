#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int sum = 0;
bool backtrack(vector<int>& sticks, int sides[4], int pos) {
    if (pos == sticks.size()) 
    {
        return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
    }
    
    for (int i = 0; i < 4; i++) 
    {
        sides[i] += sticks[pos];
        if((sides[i]*4)>sum) 
        {
            sides[i] -= sticks[pos];
            continue;
        }
        if (backtrack(sticks, sides, pos + 1)) 
        {
            return true;
        }
        sides[i] -= sticks[pos];
    }

    return false;
}

bool canFormSquare(vector<int>& sticks) {
    if (sticks.size() < 4) 
    {
        return false;
    }

    sum = 0;
    for (int stick : sticks) 
    {
        sum += stick;
    }
    if (sum % 4 != 0) {
        return false;
    }

    sort(sticks.begin(), sticks.end(), greater<int>());
    int sides[4] = {0, 0, 0, 0};
    return backtrack(sticks, sides, 0);
}


int main() {
    int t, n, stick;
    cin >> t;
    while (t--) 
    {
        cin >> n;
        vector<int> sticks;
        for (int i = 0; i < n; i++) 
        {
            cin >> stick;
            sticks.push_back(stick);
        }
        cout << (canFormSquare(sticks) ? "yes" : "no") << endl;
    }
    return 0;
}
