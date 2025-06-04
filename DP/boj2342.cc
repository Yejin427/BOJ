#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int dp[100001][5][5];
int ans;
int cost(int cur, int nxt) {
    if(cur == 0) return 2;
    else if(cur == nxt) return 1;
    else if(cur % 2 == nxt % 2) return 4;
    else return 3;
}
int solve(int l, int r, int idx) {
    if(idx == v.size()) return 0;
    if(dp[idx][l][r] != 0) return dp[idx][l][r];

    int nxt = v[idx];
    return dp[idx][l][r] = min(solve(nxt, r, idx+1) + cost(l, nxt), solve(l, nxt, idx+1) + cost(r, nxt));
}
int main(){
    int n;
    while(cin >> n && n != 0) {
        v.push_back(n);
    }
    cout << solve(0,0,0);
}