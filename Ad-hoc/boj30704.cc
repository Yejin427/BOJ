#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        if(n == 1) cout << 4;
        else if(n == 2) cout << 6;
        else if(n == 3) cout << 8;
        else {
            int l = sqrt(n);
            int q = n / l, r = n % l;
            if(r == 0) {
                cout << 2 * q + 2 * l;
            } else {
                cout << 2 * (q+1) + 2 * l;
            }
        }
        cout << '\n';
    }
}