#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d,p,q; cin >> d >> p >> q;
    int ponly = d / p, qonly = d / q;

    if(p < q) {
        int ans = (qonly + 1) * q;
        for(int i = qonly; i >= 0; i--) {
            int Q = (d - i * q) / p;
            int rest = (d - i * q) % p;
            if(!rest) {
                ans = d;
                break;
            }
            if(ans == i * q + (Q+1) * p) break;
            ans = min(ans, i * q + (Q+1) * p);
        }
        cout << ans;
    }
    else if(q < p){
        int ans = (ponly + 1) * p;
        for(int i = ponly; i >= 0; i--) {
            int Q = (d - i * p) / q;
            int rest = (d - i * p) % q;
            if(!rest) {
                ans = d;
                break;
            }
            if(ans == i * p + (Q+1) * q) break;;
            ans = min(ans, i * p + (Q+1) * q);
            // cout << "ans: "<<ans<<'\n';
        }
        cout << ans;
    }
    else {
        if(d % q == 0) cout << d;
        else cout << q * (qonly + 1);
    }
}