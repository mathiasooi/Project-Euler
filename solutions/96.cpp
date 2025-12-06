#include <iostream>
#include <string>
#include <vector>

using std::cin, std::cout;

bool solve(int (&board)[9][9]) {
    // each entry has 10 possible states
    // 0: empty
    // 1-9: number filled in
    for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
            if (board[x][y]) continue;

            std::vector<bool> allowed(10);
            for (int i = 1; i <= 9; ++i) allowed[i] = true;

            for (int i = 0; i < 9; ++i) {
                if (board[x][i] > 0) allowed[board[x][i]] = false;
                if (board[i][y] > 0) allowed[board[i][y]] = false;
            }
            int bx = (x / 3) * 3, by = (y / 3) * 3;
            for (int i = bx; i < bx + 3; ++i) {
                for (int j = by; j < by + 3; ++j){
                    if (board[i][j] > 0) allowed[board[i][j]] = false;
                }
            }

            for (int i = 1; i <= 9; ++i) {
                if (allowed[i]) {
                    board[x][y] = i;
                    if (solve(board)) return true;
                }
            }
            // Backtrack
            board[x][y] = 0;
            return false;

        }
    }
    return true;
}

int main() {
    int tests = 50;
    int board[9][9];
    int ans = 0;

    std::string line;

    for (int t = 0; t < tests; ++t) {
        std::getline(cin, line);
        for (int i = 0; i < 9; ++i) {
            std::getline(cin, line);
            for (int j = 0; j < 9; ++j) {
                board[i][j] = line[j] - '0';
            }
        }
        solve(board);
        ans += 100 * board[0][0] + 10 * board[0][1] + board[0][2];
    }
    cout << ans << std::endl;
}