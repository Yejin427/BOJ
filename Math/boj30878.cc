#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    int m; cin >> m;

    int b = 60 * 60 * 60;
    int a = m * m * (180 - 2*m);
    int g = gcd(b, a);
    cout << a/g << "/" << b/g;
}