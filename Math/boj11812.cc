#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k,q; cin >> n >> k >> q;
    for(int i=1;i<=q;i++){
        ll a,b; cin >> a >> b;
        if(k == 1){
            cout << abs(a-b)<<'\n';
            continue;
        }
        vector<ll> pa;
        vector<ll> pb;
        ll fa = a, fb = b;
        while(fa != 0){
            pa.push_back(fa);
            ll ra = fa % k;
            if(ra == 1) {
                fa = (fa - 1) / k;
            }
            else if(ra == 0) {
                fa = fa / k;
            }
            else {
                ll pos = ra - 1;
                fa = (fa + k - 1 - pos) / k;
            }
        }
        while(fb != 0){
            pb.push_back(fb);
            ll rb = fb % k;
            if(rb == 1) {
                fb = (fb - 1) / k;
            }
            else if(rb == 0) {
                fb = fb / k; 
            }
            else {
                ll pos = rb - 1;
                fb = (fb + k - 1 - pos) / k;
            }
        }
        if(pa.size() == 1){
            cout << pb.size() - 1<<'\n';
        }
        else if(pb.size() == 1){
            cout << pa.size() - 1<<'\n';
        }
        else{
            int pos1 = pa.size() - 1;
            int pos2 = pb.size() - 1;
            while(pa[pos1] == pb[pos2]){
                pos1--; pos2--;
            }
            cout << pos1 + pos2 + 2 << '\n';
        }
    }
}