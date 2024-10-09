#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[100001];
int dp[100001][2];
bool visited[100001];
void treedp(int root) {
    visited[root] = true;
    dp[root][1] = 1;
    for(int ch: v[root]){
        if(!visited[ch]) {
            treedp(ch);
            dp[root][0] += dp[ch][1];
            dp[root][1] += min(dp[ch][0], dp[ch][1]);
        }
    }
}
int main(){
    int n; cin >> n;
    for(int i=1;i<n;i++) {
        int x,y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    treedp(1);
    cout << min(dp[1][0], dp[1][1]);
}