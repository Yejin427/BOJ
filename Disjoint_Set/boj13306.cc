#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int parent[200001];
int save[200001];
vector<pair<int,pair<int,int>>> query;
int find(int x){
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void merge(int x, int y){
    int rx = find(x);
    int ry = find(y);
    parent[ry] = rx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=2;i<=n;i++){
        int b; cin >> b;
        save[i] = b;
    }
    for(int i=1;i<=(n-1+q);i++){
        int x; cin >> x;
        if(x == 1){
            int a,b; cin >> a >> b;
            query.push_back({1,{a,b}});
        }
        else{
            int a; cin >> a;
            query.push_back({0, {a, 0}});
        }
    }
    string ans = "";
    for(int i=query.size()-1;i>=0;i--){
        pair<int,pair<int,int>> qu = query[i];
        if(qu.first == 1){
            if(find(qu.second.first) == find(qu.second.second)){
                ans += '1';
            }
            else ans += '0';
        }
        else{
            merge(qu.second.first, save[qu.second.first]);
        }
    }
    for(int i=ans.length()-1;i>=0;i--){
        if(ans[i] == '1'){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

}