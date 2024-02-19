#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    vector<int> presum(n);
    int sum =0;
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum+=nums[i];
        presum[i]=sum;
    }
    
    int count = 0;

    for(int i=0;i<n;i++) 
    {
        if(presum[i] == x) 
        {
            ++count;
        }

        for(int y=i+1;y<n;y++)
        {
            if((presum[y]-presum[i])==x)
            {
                ++count;
            }
        }
    }

    cout << count ;

    return 0;
}