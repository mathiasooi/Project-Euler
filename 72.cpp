#include <iostream>
#include <vector>

using std::cout;

std::vector<int> phi(1000001, 0); 

int main() {
    long long ans = 0;
    for (int i = 0; i < 1000001; ++i) {
        phi[i] = i;
    }
    for (int i = 2; i < 1000001; ++i) {
        if (phi[i] == i) {
            for (int j = 1; j * i < 1000001; ++j) {
                phi[i*j] -= phi[i*j] / i;
            }
        }
        ans += phi[i];
    }
    cout << ans << std::endl;
}