#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using pi = pair<int,int>;
bool visited[1001];
struct cmp {
    bool operator()(pi a, pi b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

priority_queue<pi, vector<pi>, cmp> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        for(int i=1;i<=m;i++){
            int a,b; cin >> a >> b;
            pq.push({a, b});
        }

        int ans = 0;
        while(!pq.empty()){
            pi f = pq.top();
            int a = f.first;
            int b = f.second;

            for(int i=a;i<=b;i++){
                if(!visited[i]){
                    visited[i] = true;
                    ans++;
                    break;
                }
            }
            pq.pop();
        }
        memset(visited, false, sizeof(visited));
        cout << ans << '\n';
    }
}