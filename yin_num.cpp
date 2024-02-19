// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;


// int main() {
//     int N;
//     vector<int> factors;

//     cin >> N;

//     for (int i = 1; i * i <= N; i++) {
//         if (N % i == 0) {
//             factors.push_back(i);
//             if (i != N/i) {
//                 factors.push_back(N/i);
//             }
//         }
//     }

//     sort(factors.begin(), factors.end());

//     for (int factor : factors) {
//         cout << factor << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll mulmod(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (2 * a) % m;
        b >>= 1;
    }
    return res;
}

ll powermod(ll base, ll exponent, ll mod) {
    ll result = 1;
    while (exponent) {
        if (exponent & 1) result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        exponent >>= 1;
    }
    return result;
}

bool miller_rabin(ll n, int iterations = 5) {
    if (n < 4) return n == 2 || n == 3;

    for (int i = 0; i < iterations; i++) {
        ll a = 2 + rand() % (n - 3);
        ll x = powermod(a, n - 1, n);
        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int r = 1; r < 31; r++) {
            x = mulmod(x, x, n);
            if (x == 1) return false;
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

ll pollards_rho(ll n) {
    if (n == 1) return n;
    if (n % 2 == 0) return 2;

    ll x = (rand() % (n - 2)) + 2;
    ll y = x;
    ll c = (rand() % (n - 1)) + 1;
    ll d = 1;

    while (d == 1) {
        x = (mulmod(x, x, n) + c + n) % n;
        y = (mulmod(y, y, n) + c + n) % n;
        y = (mulmod(y, y, n) + c + n) % n;
        d = __gcd(abs(x - y), n);
        if (d == n) return pollards_rho(n);
    }
    return d;
}

int main() {
    srand(time(0));
    ll n;
    cin >> n;

    if (miller_rabin(n)) {

        return 0;
    }

    while (n > 1 && !miller_rabin(n)) {
        ll factor = pollards_rho(n);
        cout << factor << " ";
        while (n % factor == 0) n /= factor;
    }
    if (n > 1) cout << n;

    return 0;
}