#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while(v.size() >= 2){
        int minute = *(v.end() - 2);
        int push = v.back() - minute;
        v.pop_back();
        v.pop_back();
        if(push != 0) v.push_back(push);
        sort(v.begin(), v.end());
        ans += minute;
    }
    if(v.size() == 1){
        ans += v.back();
    }
    if(ans > 1440) cout << "-1";
    else cout << ans;
}