#include <iostream>
using namespace std;

double pow(double x, int n) {
    double ans = 1.0;
    long long nn = n;

    if (nn < 0)
        nn *= -1;

    while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn -= 1;
        }
        else {
            x = x * x;
            nn /= 2;
        }
    }

    if (n < 0)
        ans = 1.0 / (double) ans;

    return ans;
}

int main() {
    int x = 2;
    int n = 10;

    cout << pow(x, n) << endl;
    return 0;
}