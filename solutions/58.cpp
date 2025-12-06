#include <iostream>
#include <vector>

using std::cout;

std::vector<bool> prime(100000, true);

// Fom OEIS
int NE(int n) {return 4*n*n - 10*n + 7;}
int NW(int n) {return 4*n*n + 1;}
int SW(int n) {return 4*n*n - 6*n + 3;}

int main() {
    for (int p = 2; p*p < 100000; ++p) {
        if (prime[p]) {
            for (int j = p * p; j < 100000; j += p) {
                prime[j] = false;
            }
        }
    }
    int good = 0;
    for (int i = 1; ; ++i) {
        if (prime[NE(i)]) good++;
        if (prime[NW(i)]) good++;
        if (prime[SW(i)]) good++;
        cout << 2*i+1 << ' ' << good << ' ' << i*4+1 << std::endl;
        if (good*1.0/(i*4+1) < 0.1) {
            cout << 2*i+1 << std::endl;
            break;
        }
    }
}