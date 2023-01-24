#include<bits/stdc++.h>
using namespace std;
long long s[1000001];
int p[1000001];
bool gongsa[1000001];
vector<long long> v;
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
void merge(int x, int y){
    int px = find(x);
    int py = find(y);
    p[py] = px;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; long long k; cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        cin >> s[i];
        p[i] = i;
    }
    while(m--){
        int i,j; cin >> i >> j;
        if((i==1 && j==n) || (i==n && j==1)) gongsa[n] = true;
        else if(i<j) gongsa[i] = true;
        else gongsa[j] = true;
    }
    if(m == 0 || m == 1){
        cout << "YES";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!gongsa[i]){
            if(i == n) merge(n, 1);
            else merge(i, i+1);
        }
    }
    int x = 1; int y = 1;
    while(x <= n){
        long long dol = 1000000;
        while(y <= n && find(x) == find(y)){
            dol = min(dol, s[y]);
            y++;
        } 
        x = y;
        v.push_back(dol);
    }

    if(find(1) == find(n)){
        if(v.front() > v.back()){
            v.erase(v.begin());
        }
        else v.pop_back();
    }
    long long cnt = 0;
    for(auto& dol: v){
        cnt += dol;
    }
    if(cnt <= k) cout << "YES";
    else cout << "NO";
}