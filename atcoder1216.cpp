#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N; 

    string result = "";
    for (int i = 0; i < N; ++i) {
        result += to_string(N); // 將N轉換為字符串並連接到result
    }

    cout << result << endl; 

    return 0;
}
