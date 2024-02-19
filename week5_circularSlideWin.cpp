#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printMaxInWindow(const vector<int>& nums, int k) 
{
    deque<int> Qi(k);
    int i;

    // Process first k
    for (i = 0; i < k; ++i) 
    {
        // For every element, the previous smaller elements are useless so remove them from Qi

        while ((!Qi.empty()) && nums[i] >= nums[Qi.back()]) Qi.pop_back(); 

        Qi.push_back(i);
    }

    // Process rest of the elements, i.e., from nums[k] to nums[n-1]
    for (; i < nums.size(); ++i) {
        // The element at the front of the queue is the largest element of previous window, so print it
        cout << nums[Qi.front()] << " ";

        // Remove the elements which are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k) Qi.pop_front(); // Remove from front of queue

        // Remove all elements smaller than the currently being added element (remove useless elements)
        while ((!Qi.empty()) && nums[i] >= nums[Qi.back()]) Qi.pop_back();

        // Add current element at the rear of Qi
        Qi.push_back(i);
    }

    // Print the maximum element of last window
    cout << nums[Qi.front()];
}

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> nums(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> nums[i];
    }

    // To handle the circular array, we need to consider the array twice
    vector<int> extended_nums(nums.begin(), nums.end());
    extended_nums.insert(extended_nums.end(), nums.begin(), nums.begin() + k - 1);//   [first, last) 所以是原數組+k-1個元素(nums[0]~nums[k-2])

    printMaxInWindow(extended_nums, k);

    return 0;
}
