#include <iostream>
#include <vector>
using namespace std;

vector<string> generateGrayCode(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    
    // Generate the Gray code for n-1
    vector<string> previous = generateGrayCode(n - 1);
    vector<string> result;
    
    // Prepend '0' to each string in G(n-1)
    for (const string &s : previous) {
        result.push_back("0" + s);
    }
    
    // Prepend '1' to each string in reverse of G(n-1)
    for (int i = previous.size() - 1; i >= 0; i--) {
        result.push_back("1" + previous[i]);
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> grayCode = generateGrayCode(n);
    for (const string &s : grayCode) {
        cout << s << endl;
    }

    return 0;
}
