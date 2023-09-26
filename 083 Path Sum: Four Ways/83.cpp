#include <iostream>
#include <queue>
#include <vector>

using std::cout, std::cin;

struct Node {
    int w, x, y;

    Node(int _w, int _x, int _y) : w(_w), x(_x), y(_y) {}

    bool operator>(const Node &other) const {
        return w > other.w;
    }
};

const int n = 80;
int arr[n][n];
bool v[n][n] = {false};

int main() {
    std::freopen("matrix.txt", "r", stdin);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            cin.ignore();
        }
    }
    // Shortest path solution
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.emplace(Node(arr[0][0], 0, 0));

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        auto && [w, x, y] = curr;

        if (v[x][y]) continue;
        v[x][y] = true;

        // cout << w << ' ' << x << ' ' << y << std::endl;

        if (x == n - 1 && y == n - 1) {
            cout << w << std::endl;
            break;
        }

        if (x > 0) pq.emplace(Node(w + arr[x-1][y], x-1, y));
        if (y > 0) pq.emplace(Node(w + arr[x][y-1], x, y-1));
        if (x < n - 1) pq.emplace(Node(w + arr[x+1][y], x+1, y));
        if (y < n - 1) pq.emplace(Node(w + arr[x][y+1], x, y+1));
    }
}