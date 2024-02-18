#include<iostream>
#include<string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        
        int l = 0, r = str.length() - 1;
        int ans = 0;
        while(l <= r) {
            if(str[l] == str[r]) {
                l++;
                r--;
            } else {
                ans = 1;
                break;
            }
        }
        if(ans) {
            int ll = l+1, rr = r;
            while(ll <= rr) {   //왼쪽 지워보기
                if(str[ll] == str[rr]) {
                    ll++; rr--;
                } else {
                    ans = 2;
                    break;
                }
            }
            if(ans == 2) {
                ll = l, rr = r-1;   //오른쪽 지워보기
                while(1) {
                    if(ll > rr) {
                        ans = 1;
                        break;
                    }
                    if(str[ll] == str[rr]) {
                        ll++; rr--;
                    } else {
                        ans = 2;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}