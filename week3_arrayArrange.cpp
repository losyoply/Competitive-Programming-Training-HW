#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
// 這題目的思路是使用雙向鏈表 (doubly linked list) 來解決。當我們需要移動頭部或尾部時，雙向鏈表的操作時間複雜度是 
// O(1)。而查找特定值的時間複雜度是 
// O(n)。但我們可以使用哈希表 (hash table) 來儲存每個值的節點位置，這樣查找的時間複雜度就變成 
// O(1) 了。

// 以下是演算法的步驟：
// 創建一個從 1 到 n 的雙向鏈表。
// 使用哈希表存儲每個值的節點位置。
// 對於每一個查詢：
// a. 使用哈希表找到值的節點。
// b. 根據查詢類型 (H 或 T) 將節點移動到鏈表的頭部或尾部。
// 輸出鏈表的所有值。


void processQueries(int n, int q) {
    list<int> sequence;
    unordered_map<int, list<int>::iterator> positions; //!

    // Initialize the sequence and positions.
    for (int i = 1; i <= n; ++i) 
    {
        sequence.push_back(i);
        positions[i] = --sequence.end();
    }

    char queryType;
    int value;
    for (int i = 0; i < q; ++i) 
    {
        cin >> queryType >> value;

        // Move to head
        if (queryType == 'H') 
        {
            sequence.erase(positions[value]);
            sequence.push_front(value);
            positions[value] = sequence.begin();
        }
        // Move to tail
        else if (queryType == 'T') 
        {
            sequence.erase(positions[value]);
            sequence.push_back(value);
            positions[value] = --sequence.end();
        }
    }

    // Print the sequence.
    for (int x : sequence) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t, n, q;
    cin >> t;

    while (t--) 
    {
        cin >> n >> q;
        processQueries(n, q);
    }

    return 0;
}