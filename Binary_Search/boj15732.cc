#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>> rules;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, d; cin >> n >> k >> d;
    for(int i=1;i<=k;i++){
        int a,b,c; cin >> a >> b >> c;
        rules.push_back({{a,b},c});
    }
    int left = 1; int right = n;  int ans = 0;
    //mid 번째 도토리의 상자를 구해야
    while(left <= right){
        int mid = (left + right) / 2;

        long long value = 0;
        for(int i = 0; i < k; i++){
            int end = min(rules[i].first.second, mid);
            if(end >= rules[i].first.first){
                value += ((end - rules[i].first.first) / rules[i].second) + 1;
            }
        }

        if(value >= d){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans;
}