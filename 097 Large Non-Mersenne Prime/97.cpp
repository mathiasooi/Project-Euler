#include <iostream>

using std::cout;

typedef unsigned long long ll;

ll MOD = 1e12;

// ll binpow(ll a, ll b) {
//     ll res = 1;
//     while (b > 0) {
//         // cout << res << ' ' << a << ' ' << b << ' ' << '\n';
//         if (b & 1)
//             res = (res % MOD * a % MOD) % MOD;
//         a = (a % MOD * a % MOD) % MOD;
//         b >>= 1;
//     }
//     return res;
// }

int main() {
    // cout << binpow(2, 7830457) << std::endl;
    // cout << 28433 * binpow(2, 7830457) + 1 << std::endl;

    ll res = 1;
    for (int i = 0; i < 7830457; ++i) {
        res = (res * 2) % MOD;
    }
    res = (res * 28433) % MOD;
    cout << res << std::endl;
}