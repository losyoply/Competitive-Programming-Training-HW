#include <iostream>
#include <vector>
using namespace std;
int digsum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int findGoodTriples(int n) {
    int count = 0;
    int sum_n = digsum(n);
    for (int a = 0; a <= n; a++) {
        for (int b = 0; b + a <= n; b++) {
            int c = n - a - b;
            if (digsum(a) + digsum(b) + digsum(c) == sum_n) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t, n;
    cin >> t; 
    while (t--) {
        cin >> n; 
        cout << findGoodTriples(n) << endl; 
    }

    return 0;
}
