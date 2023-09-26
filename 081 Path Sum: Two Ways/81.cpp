#include <iostream>

using std::cout, std::cin;

const int n = 80;
int dp[n+5][n+5] = {0};

int main() {
    std::freopen("test.txt", "r", stdin);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            cin.ignore();
            if (i == 1 && j == 1) dp[i][j] = x;
            else if (i == 1) dp[i][j] = dp[i][j-1] + x;
            else if (j == 1) dp[i][j] = dp[i-1][j] + x;
            else dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + x;
        }
    }
    cout << dp[n][n] << std::endl;
}