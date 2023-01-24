#include<bits/stdc++.h>
using namespace std;
int a[4001];
int b[4001];
int c[4001];
int d[4001];
vector<int> v1;
vector<int> v2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v1.push_back(a[i]+b[j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v2.push_back(c[i]+d[j]);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    long long cnt = 0;
    for(auto& i: v1){
        long long idx, idx2;
        if(i <= 0){  //그에 맞는 양수를 구해야함
            idx = lower_bound(v2.begin(), v2.end(), -i) - v2.begin();
            idx2 = lower_bound(v2.begin(), v2.end(), -i+1) - v2.begin();
        }
        else{   //그에 맞는 음수를 구해야함
            idx2 = upper_bound(v2.begin(), v2.end(), -i) - v2.begin();
            idx = upper_bound(v2.begin(), v2.end(), -i-1) - v2.begin();
        }
        cnt += (idx2 - idx);
    }
    cout << cnt;
}