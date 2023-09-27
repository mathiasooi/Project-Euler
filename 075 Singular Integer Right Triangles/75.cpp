#include <iostream>
#include <numeric>
#include <vector>

using std::cout;

std::vector<int> v(1500001, 0);

// Generate all primitive triples (Euclids formula)

int main() {
    for (int n = 1; n < 1300; ++n) {
        for (int m = n + 1; m < 1300; ++m) {
            if (n % 2 == 1 && m % 2 == 1) continue;
            if (std::gcd(m, n) != 1) continue;
            int a = m*m - n*n;
            int b = 2*m*n;
            int c = m*m + n*n;
            // cout << a << ' ' << b << ' ' << c << std::endl;
            for (int k = 1; k*(a+b+c) <= 1500000; ++k) {
                v[k*(a+b+c)]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1500000; ++i) {
        ans += v[i] == 1;
    }
    cout << ans << std::endl;
}

