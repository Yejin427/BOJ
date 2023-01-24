#include<bits/stdc++.h>
using namespace std;
int a[1001];
int dpa[1001];
int cuta[1000001];
int b[1001];
int dpb[1001];
int cutb[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size; cin >> size;
    int m,n; cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        dpa[i] = dpa[i-1]+a[i];
    }
    int asum = dpa[m];
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        dpb[i] = dpb[i-1]+b[i];
    }
    int bsum = dpb[n];
    
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int value1 = dpa[j] - dpa[i-1];
            cuta[value1]++;
            if(i != j){
                int value2 = asum - dpa[j-1] + dpa[i];
                cuta[value2]++;
            }
        }
    }
    cuta[asum] = 1; cuta[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int value1 = dpb[j] - dpb[i-1];
            cutb[value1]++;
            if(i != j){
                int value2 = bsum - dpb[j-1] + dpb[i];
                cutb[value2]++;
            }
        }
    }
    cutb[bsum] = 1; cutb[0] = 1;
    long long ans = 0;
    // for(int i=0;i<=asum;i++) cout << cuta[i] <<" ";
    // cout <<'\n';

    // for(int j=0;j<=bsum;j++) cout << cutb[j] << ' ';
    // cout <<'\n';
    for(int i=0;i<=size;i++){
        ans += cuta[i] * cutb[size - i];
    }
    cout << ans;
}