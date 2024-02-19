#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long int mod(long long int a, long long int b) 
{
    return (a  + b) % b;
}

int bfsMinDiceRolls(long long int n, long long int x, const vector<long long int>& diceSides) 
{
    vector<bool> visited(n + 1, false);
    queue<pair<long long int, int>> q; //(current position, number of rolls)
    q.push({1, 0}); // Start from square 1 with 0 rolls

    while (!q.empty()) 
    {
        long long int position = q.front().first;
        int rolls = q.front().second;
        q.pop();

        if (position == x) 
        {
            return rolls;
        }

        // Try each possible move 
        for (long long int move : diceSides) 
        {
            long long int newPosition = mod(position * move, n);

            if (newPosition == 0) 
            {
                newPosition = n;
            }
            if (!visited[newPosition]) 
            {
                visited[newPosition] = true;
                q.push({newPosition, rolls + 1});
            }
        }
    }
    return -1;
}

int main() 
{
    long long int n, x, k;
    
    cin >> n >> x >> k;
    
    vector<long long int> diceSides(k);
    for (int i = 0; i < k; ++i) 
    {
        cin >> diceSides[i];
    }

    int result = bfsMinDiceRolls(n, x, diceSides);
    if (result == -1) 
    {
        cout << "I LOVE TSING HUA" << endl;
    } 
    else 
    {
        cout << result << endl;
    }

    return 0;
}
