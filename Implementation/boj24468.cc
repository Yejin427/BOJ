#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int s[1001];
bool c[1001];
vector<int> v[1001];
int main(){
    int l,n,t; cin >> l >> n >> t;
    for(int i=1;i<=n;i++){
        char d;
        cin >> s[i] >> d;
        if(d == 'R') c[i] = true;
    }
    int time = 1;
    int ans = 0;
    while(time <= t){
        for(int i=1;i<=n;i++){
            if(c[i]) s[i] += 1;
            else s[i] -= 1;
        }
        for(int i=1;i<=n;i++){
            v[s[i]].push_back(i);
        }
        for(int i=0;i<=l;i++){
            if(v[i].size() == 2){//방향 바꿈
                c[v[i][0]] = !c[v[i][0]];
                c[v[i][1]] = !c[v[i][1]];
                ans++;
            }
            else if((i == 0 || i == l) && v[i].size()){
                c[v[i][0]] = !c[v[i][0]];
            }
            v[i].clear();
        }
        time++;
    }
    cout << ans;
}