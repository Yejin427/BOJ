#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
using pii = pair<pair<int,int>, bool>;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pair<int,int>> v[50001];
int ans[50001];
bool gh[50001];
vector<int> dest;
int main(){
    int T; cin >> T;
    while(T--){
        int n,m,t; cin >> n >> m >> t;
        int s,g,h; cin >> s >> g >> h;
        for(int i=1;i<=m;i++){
            int a,b,d; cin >> a >> b >> d;
            v[a].push_back({b, d});
        }
        vector<int> dest;
        for(int i=1;i<=t;i++){
            int x; cin >> x;
            dest.push_back(x);
        }
        sort(dest.begin(), dest.end());
        memset(ans, -1, sizeof(ans));
        memset(gh, false, sizeof(gh));
        pq.push({{0, s}, false});
        while(!pq.empty()){
            int dest = pq.top().first.first;
            int edge = pq.top().first.second;
            bool smell = pq.top().second;
            cout << "dest: "<<dest<<" edge: "<<edge<<" smell: "<<smell<<'\n';
            pq.pop();
            if(ans[edge] != -1) continue;
            ans[edge] = dest;
            gh[edge] = smell;
            for(auto& nxt: v[edge]){
                if(ans[nxt.first] != -1) continue;
                if((edge == g && nxt.first == h) || (edge == h && nxt.first == g)){
                    pq.push({{nxt.first, dest + nxt.second}, true});
                }
                else{
                    pq.push({{nxt.first, dest + nxt.second}, smell});
                }
            }
        }
        for(int d: dest){
            if(gh[d]) cout << d << ' ';
        }
        cout << '\n';
    }
}