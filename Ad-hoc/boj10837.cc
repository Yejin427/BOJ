#include<iostream>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k,c; cin >> k >> c;
    while(c--){
        int m,n; cin >> m >> n;
        if(m==n) cout << 1;
        else if(m > n) {
            if(m-n - (k-m) <= 2){
                cout << 1;
            }
            else cout << 0;
        }
        else{
            if(n-m-(k-n)<=1){
                cout << 1;
            }
            else cout << 0;
        }
        cout << '\n';
    }
}