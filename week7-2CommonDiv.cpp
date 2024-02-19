#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int size, content;
    cin >> size;
    vector<int> exist(1000001, 0);
    
    for (int i = 0; i < size; i++) 
    {
        cin >> content;
        exist[content]++;
    }

    for (int divisor = 1000000; divisor > 0; divisor--) 
    {
        int count = 0;
        for (int i = 1; i * divisor <= 1000000; i++) 
            count += exist[i * divisor];
            
        if (count >= 2) 
        {
            cout << divisor << endl;
            return 0;
        }
    }

    return 0;
}