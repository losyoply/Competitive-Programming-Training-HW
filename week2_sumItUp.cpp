#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void findSums(int t, const vector<int>& nums, int idx, int currSum, vector<int>& currComb, set<vector<int>>& results) 
{
    if (currSum == t) 
    {
        results.insert(currComb);
        return;
    }
    if (idx == nums.size() || currSum > t) return;

    // Include this number
    currComb.push_back(nums[idx]);
    findSums(t, nums, idx + 1, currSum + nums[idx], currComb, results);
    currComb.pop_back();

    // Exclude this number and move to the next distinct number
    while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) idx++;
    findSums(t, nums, idx + 1, currSum, currComb, results);
}
int main() 
{
    int t, n;
    while (cin >> t >> n && n) 
    {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> nums[i];
        }

        set<vector<int>> results;
        vector<int> currComb;
        cout << "Sums of " << t << ":" << endl;

        // sort in descending order to start with bigger numbers first
        sort(nums.rbegin(), nums.rend());
        findSums(t, nums, 0, 0, currComb, results);

        if (results.empty()) 
        {
            cout << "NONE" << endl;
        } 
        else 
        {
            for (auto rit = results.rbegin(); rit != results.rend(); ++rit) 
            {
                const auto& result = *rit;
                for (size_t i = 0; i < result.size(); ++i) 
                {
                    if (i > 0) cout << "+";
                    cout << result[i];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
