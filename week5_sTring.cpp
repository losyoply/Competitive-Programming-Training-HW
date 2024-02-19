#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string X;
    cin >> X;

    stack<char> s;

    for (char c : X) 
    {
        if (c == 'S') 
        {
            s.push(c);
        } 
        else if (!s.empty() && s.top() == 'S') { //c is T
            s.pop(); // Remove 'ST'
        } 
        else
        {
            s.push(c);
        }
    }

    cout << s.size() << endl; // Remaining characters in the stack

    return 0;
}
