#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    string str; cin >> str;
    vector<int> v;  //ioioi 연속 횟수 저장
    int ans = 0;
    int idx = 0, cur = 0;
    while(idx < m){
        if(str[idx] == 'I' && str[idx+1] == 'O' && str[idx+2] == 'I'){
            cur++;
            idx += 2;
        }
        else{
            if(cur > 0) v.push_back(cur);
            cur = 0;
            idx++;
        }
    }
    for(auto i: v){
        if(i >= n) ans += (i - n + 1);
    }
    cout << ans;
}