#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; string s;
        cin >> n >> s;

        int first0 = -1, last0 = -1, first1 = -1, last1 = -1;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') {
                if(first1 == -1) first1 = i+1;
                last1 = i+1;
            }
            if(s[i] == '0') {
                if(first0 == -1) first0 = i+1;
                last0 = i+1;
            }
        }
        //긴 구간을 줄이거나 짧은 구간을 늘림.. 아니면 둘다
        if(n == 1 || n == 3) {
            cout << -1 << '\n';
            continue;
        }
        if(n == 2) {
            if(s == "11" || s == "00") cout << 1 <<'\n';
            else cout << 0 << '\n';
            continue;
        }
        if(last0 - first0 == last1 - first1) {
            cout << 0 << '\n';
            continue;
        }
        if(last0 - first0 == n-1) {
            if(last1 == n-1 || first1 == 2) {
                if(last1 == n-1 && first1 == 2) {
                    cout << 2 << '\n';
                }
                else cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
        else if(last1 - first1 == n-1) {
            if(last0 == n-1 || first0 == 2) {
                if(last0 == n-1 && first0 == 2) {
                    cout << 2 << '\n';
                }
                else cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
        else {
            cout << 1 << '\n';
        }
    }
}