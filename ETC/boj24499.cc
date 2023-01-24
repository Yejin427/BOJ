#include<iostream>
#include<algorithm>
using namespace std;
int sum[100001];
int main(){
    int k,n; cin >> n >> k;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        sum[i] = sum[i-1] + a;
    }
    int ans = 0;
    for(int i=0;i<=n-k;i++){
        ans = max(ans, sum[i+k] - sum[i]);
    }
    for(int i=n-k+1;i<=n;i++){
        ans = max(sum[n] - (sum[i] - sum[i-n+k]), ans);
    }
    cout << ans;
}