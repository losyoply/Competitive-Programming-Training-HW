#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int &x : nums) {
        cin >> x;
    }

    stack<int> s;
    vector<int> result(n);

    for (int i = 0; i < n; ++i) 
    {
        while (!s.empty() && nums[s.top()] >= nums[i]) 
        {
            s.pop(); // 弹出所有比当前元素大的位置
        }
        result[i] = s.empty() ? 0 : s.top() + 1; // 栈为空则输出0，否则输出栈顶位置+1
        s.push(i); // 将当前位置推入栈中
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " "; // 输出结果
    }
    cout << endl;

    return 0;
}
