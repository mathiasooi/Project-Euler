#include<iostream>
#include<string>

typedef unsigned long long ll;

using std::cout;

std::string pattern = "UDDDUdddDDUDDddDdDddDDUDDdUUDd";
const int n = pattern.length();

std::string mod_collatz(ll x) {
    std::string s;
    while (x > 1) {
        if (x % 3 == 0) {
            s += "D";
            x /= 3;
        }
        else if (x % 3 == 1) {
            s += "U";
            x = (4 * x + 2) / 3;
        }
        else {
            s += "d";
            x = (2 * x - 1) / 3;
        }
    }
    return s;
}

bool good(ll x) { return mod_collatz(x).substr(0, n) == pattern;}

int main() {
    for (ll x = 1; x < 1000; ++x) {
        cout << x << " " << mod_collatz(x) << std::endl;
    }
}