#include <iostream>
#include <vector>
#include <set>

using std::cout;

int n = 50000000;

std::vector<bool> prime(10000, true);  // 10000 > sqrt(n)
std::vector<long long> ps;

void preprocess() {
    for (int p = 2; p*p < 10000; ++p) {
        if (prime[p]) {
            for (int j = p * p; j < 10000; j += p) {
                prime[j] = false;
            }
        }
    }
    for (int p = 2; p < 10000; ++p) {
        if (prime[p]) {
            ps.push_back(p);
        }
    }
}

int main() {
    preprocess();
    std::set<long long> s;
    for (long long a : ps) {
        for (long long b : ps) {
            for (long long c : ps) {
                long long x = a * a + b * b * b + c * c * c * c;
                if (x > n) break;
                s.insert(x);
            }
        }
    }
    // for (int i : s) cout << i << '\n';
    cout << s.size() << std::endl;
}
