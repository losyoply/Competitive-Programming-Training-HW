#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long largestRectangleArea(const vector<int>& heights) 
{
    stack<int> stack;
    long long max_area = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) 
    {
        // We push a height of 0 to the end to make sure we process all heights in the stack
        int h = (i == n ? 0 : heights[i]);

        if (stack.empty() || h >= heights[stack.top()]) 
        {
            stack.push(i);
        } 
        else 
        {
            int height = heights[stack.top()];
            stack.pop();

            long long width = stack.empty() ? i : i - stack.top() - 1;
            max_area = max(max_area, height * width);
            // We need to go back to check again with the new top of the stack
            i--;
        }
    }

    return max_area;
}

int main() {
    int n;
    while (cin >> n) 
    { // Read until EOF
        vector<int> heights(n);
        for (int i = 0; i < n; i++) cin >> heights[i];
        cout << largestRectangleArea(heights) << endl;
    }
    return 0;
}

// 如果栈为空，則寬度為當前柱子的索引 i（因為這表示從第一個柱子到當前柱子的所有柱子都不低於栈頂柱子的高度）。
// 如果栈不為空，則寬度為當前柱子的索引 i 減去新的栈頂柱子的索引再減1（因為新的栈頂柱子的索引到當前柱子的前一個索引之間的所有柱子都不低於剛剛被取出的栈頂柱子的高度）。