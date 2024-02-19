#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
    string input;
    while (getline(cin, input)) 
    { // 讀取直到EOF
        list<char> result;
        auto it = result.begin();

        for (char c : input) 
        {
            if (c == '[') 
            {
                it = result.begin();
            } 
            else if (c == ']') 
            {
                it = result.end();
            } 
            else 
            {
                result.insert(it, c);
            }
        }

        for (char c : result) 
        {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}

// std::string input;
// if (std::getline(std::cin, input)) {
//     // 讀取成功
// } else {
//     // 讀取失敗或達到文件尾部 (EOF)
// }