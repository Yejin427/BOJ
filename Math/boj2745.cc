#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
    string s; cin >> s;
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if('0' <= s[i] && s[i] <= '9') {
            ans += pow(n, s.length() - i - 1) * (s[i] - '0');
        } else {
            ans += pow(n, s.length() - i - 1) * (s[i] - 'A' + 10);
        }
    }
    cout << ans;
}