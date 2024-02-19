#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 使用两个堆来存储元素，大根堆存储较小的一半，小根堆存储较大的一半
    priority_queue<int, vector<int>, less<int>> maxHeap; // 大根堆
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小根堆

    for (int i = 0; i < n; ++i) 
    {
        int number;
        cin >> number;
        
        // 先把新元素加入大根堆
        maxHeap.push(number);
        
        // 如果大根堆顶的元素比小根堆顶的元素大，需要交换
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) 
        {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
        }
        
        // 保持两个堆的大小平衡或者大根堆比小根堆大1
        if (maxHeap.size() > minHeap.size() + 1) 
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // 中位数是大根堆的顶部元素
        cout << maxHeap.top() << " ";
    }
    cout << endl;

    return 0;
}
