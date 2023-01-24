#include<bits/stdc++.h>
using namespace std;
int choo[31];
int bead[8], n;
int dp[31][40001];  
void hap(int idx, int sum){
    if(idx == n+1 || dp[idx][sum]) return;
    if(sum > 0) dp[idx][sum]=1;
    hap(idx+1, sum+choo[idx+1]);
    hap(idx+1, abs(sum-choo[idx+1]));
    hap(idx+1, sum);
}
int main(){
    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin >> choo[i];
    }
    hap(1, choo[1]);
    hap(1, 0);
    hap(1, -choo[1]);
    int c; cin >> c;
    for(int i=1;i<=c;i++) cin >> bead[i];
    for(int i=1;i<=c;i++){
        if(bead[i] > 15000) cout << "N ";
        else if(dp[n][bead[i]]) cout << "Y ";
        else cout << "N ";
    }
}