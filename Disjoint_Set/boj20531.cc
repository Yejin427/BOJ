#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
const ll MOD = 1E9 + 7;
int parent[5001];
ll dp[5001][5001];
ll g[5001];
bool chk[5001];
ll grouping(int i, int j){ 
    if(i == j || j == 1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (grouping(i-1, j) * (ll)j + grouping(i-1, j-1)) % MOD;
}
int find(int x){
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}
void merge(int x, int y){
    int findx = find(x);
    int findy = find(y);
    parent[findy] = findx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    int group = n;

    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            g[i] += grouping(i, j);
            g[i] %= MOD;
        }
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        if(find(a) != find(b)){
            merge(a, b);
            group--;
        }
        cout << g[group] << '\n';
    }
    
}