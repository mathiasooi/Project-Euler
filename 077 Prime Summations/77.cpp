#include <iostream>
#include <vector>

using std::cout;

int dp[100000] = {0};
std::vector<bool> prime(10000, true);

int main() {
    // Generate primes up to 10000
    std::vector<int> primes;
    for (int p = 2; p*p < 10000; ++p) {
        if (prime[p]) {
            for (int j = p * p; j < 10000; j += p) {
                prime[j] = false;
            }
        }
    }
    for (int p = 2; p < 10000; ++p) {
        if (prime[p]) primes.push_back(p);
    }

    // dp[i] = # ways to sum up to i using primes
    //       = sum dp[i-p] for all prime p <= i
    dp[0] = 1;
    dp[1] = 0;
    for (int p : primes) {
        for (int i = p; i < 100000; ++i) {
            dp[i] += dp[i-p];
        }
    }
    for (int i = 2; i < 100000; ++i) {
        if (dp[i] > 5000) {
            cout << i << std::endl;
            break;
        }
    }

    // for (int i = 0; i < 100; ++i) {
    //     cout << "i: " << i << " dp[i]: " << dp[i] << '\n';
    // }
}