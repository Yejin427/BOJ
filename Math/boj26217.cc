#include<iostream>
using namespace std;

int main() {
    double n; cin >> n;
    double ans = 0;
    for(double i=1;i<=n;i++) {
        ans += n / i;
    }
    cout << fixed;
    cout.precision(10);
    cout << ans;
}