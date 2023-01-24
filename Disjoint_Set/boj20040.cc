#include<bits/stdc++.h>
using namespace std;
int parent[500001];
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int rootx = find(x);
    int rooty = find(y);
    parent[rooty] = rootx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int ans = 0;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        if(ans == 0){
            if(find(a) != find(b)){
                merge(a,b);
            }
            else ans = i;
        }
    }
    cout << ans;
}