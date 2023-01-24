#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
int dp[16][1<<16];
int w[16][16],n;
using namespace std;

int dfs(int cur, int bit){
    if(bit == (1 << n)-1){
        if(w[cur][0] == 0) return 1e9;
        else return w[cur][0];
    }
    if(dp[cur][bit] != -1) return dp[cur][bit];
    dp[cur][bit] = 1e9;
    for(int i = 0; i < n; i++){
        if(w[cur][i] == 0) continue;
        if(bit & (1 << i)) continue;
        int nbit = bit | (1 << i);
        dp[cur][bit] = min(dp[cur][bit], w[cur][i] + dfs(i, nbit));
    }
    return dp[cur][bit];
}
int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> w[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1);
}