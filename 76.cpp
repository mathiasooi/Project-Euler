#include <iostream>

using std::cout;

unsigned long long dp[105][105] = {0};  
// dp[i][j] = # ways to sum up to j using first i numbers

int main() {
    dp[0][0] = 1;
    for (int i = 1; i < 105; ++i) {
        for (int j = 0; j < 105; ++j) {
            dp[i][j] = dp[i-1][j];
            int r = j - i;
            if (r >= 0) dp[i][j] += dp[i][r];
        }
    }
    cout << dp[100][100] - 1 << std::endl;
}