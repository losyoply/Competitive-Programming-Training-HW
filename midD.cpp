
#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;

bool isFeasible(const vector<int>& c, int t, int m) 
{
    long long sum = 0;
    for (int i = 0; i < c.size(); i++) 
    {
        sum += ceil(c[i] / (double)t);//need money
        if (sum > m) return false;
    }
    return true;
}

int findMinTime(vector<int>& c, int m) 
{
    int left = 1, right = *max_element(c.begin(), c.end()); //最少要1 time, 最多要max_element time
    
    int answer = right;
    
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (isFeasible(c, mid, m)) 
        {
            answer = mid;
            right = mid - 1;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    
    return answer;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    
    for (int i = 0; i < n; i++) cin >> c[i];
    
    cout << findMinTime(c, m) << endl;
    
    return 0;
}
