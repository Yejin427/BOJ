#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;
int dp[1001][1001];
string s1, s2, ans;
int f(int l1, int l2) {
    if(l1 < 0 || l2 < 0) return 0;
    if(dp[l1][l2] != -1) return dp[l1][l2];

    if(s1[l1] == s2[l2]) {
        return dp[l1][l2] = f(l1 - 1, l2 - 1) + 1;
    }
    else {
        return dp[l1][l2] = max(f(l1 - 1, l2), f(l1, l2 - 1));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s1 >> s2;
    
    int l1 = s1.length(), l2 = s2.length();
    memset(dp, -1, sizeof(dp));
    cout << f(l1-1, l2-1) << '\n';

    int r = l1-1, c = l2-1;
    while(r >= 0 && c >= 0) {
        if(dp[r][c] == dp[r-1][c]) {
            r--;
        }
        else if(dp[r][c] == dp[r][c-1]) {
            c--;
        }
        else{
            ans += s1[r];
            r--;
            c--;
        }
    }
    // cout << ans<< '\n';
    if(ans.size() > 0){
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}