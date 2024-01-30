#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v[1000001];
int indeg[1000001];
int outdeg[1000001];
int dp[1000001];
int ans;
int dfs(int root){
    if(!v[root].size()){
        return dp[root] = 1;
    }
    for(int child: v[root]){
        dp[root] += dfs(child);
    }
    return dp[root];
}
int main(){
    int n,m; cin >> n >> m;
    while(m--){
        int a,b; cin >> a >> b;
        if(a < b){
            outdeg[a]++;
            indeg[b]++;
        }
        else{
            outdeg[b]++;
            indeg[a]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(outdeg[i] < indeg[i]) continue;
        ans += outdeg[i] - indeg[i];
    }
    cout << ans;
    
}