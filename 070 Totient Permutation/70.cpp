#include <iostream>
#include <vector>

typedef long long ll;

using std::cout;

const int MAX_PRIME = 10000;
std::vector<bool> prime(MAX_PRIME, true);  // 10000 < sqrt(10^7)
std::vector<int> ps;

void sieve() {
    for (int p = 2; p*p < MAX_PRIME; ++p) {
        if (prime[p]) {
            for (int j = p * p; j < MAX_PRIME; j += p) {
                prime[j] = false;
            }
        }
    }
    for (int p = 2; p < MAX_PRIME; ++p) {
        if (prime[p]) ps.push_back(p);
    }
}

int phi(int n) {
    int x = n;
    for (int i = 0; ps[i]*ps[i] < n; ++i) {
        if (n % ps[i] == 0) {
            x -= x / ps[i];
            while (n % ps[i] == 0) n /= ps[i];
        }
    }
    if (n > 1) x -= x / n;
    return x;
}

bool perm(int a, int b) {
    std::vector<int> d(10, 0);
    while (a) {
        d[a % 10]++;
        a /= 10;
    }
    while (b) {
        d[b % 10]--;
        b /= 10;
    }
    return std::all_of(d.begin(), d.end(), [](int i) { return i==0; });
}

int main() {
    sieve();
    int bestn = 0;
    double bestr = 100000000;
    for (int i = 2; i < 1e7; ++i) {
        int phin = phi(i);
        if (perm(i, phin)) {
            if (i*1.0/phin < bestr) {
                bestr = i*1.0/phin;
                bestn = i;
            }
        }
    } 
    cout << bestn << std::endl;
}