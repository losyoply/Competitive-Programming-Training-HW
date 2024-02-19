#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, x;
    // Read the size of the array and the target sum
    cin >> n >> x;
    vector<pair<int, int>> nums(n);

    for(int i = 0; i < n; ++i) {
        cin >> nums[i].first; 
        nums[i].second = i + 1; //index  position
    }

    sort(nums.begin(), nums.end());

    // Iterate through the array to find a triplet with the given sum
    for(int i = 0; i < n - 2; ++i) {
        int left = i + 1; // Start the left pointer just after i
        int right = n - 1; // Start the right pointer at the end of the array
        
        while(left < right) {
            int current_sum = nums[i].first + nums[left].first + nums[right].first;

            if(current_sum == x) 
            {
                cout << nums[i].second << " " << nums[left].second << " " << nums[right].second << endl;
                return 0; // We found a solution, so exit the program
            } else if(current_sum < x) 
            {
                left++; // Move the left pointer to the right to increase the sum
            } 
            else 
            {
                right--; // Move the right pointer to the left to decrease the sum
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
