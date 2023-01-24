#include<bits/stdc++.h>
using namespace std;
int arr[100001][4];
int maxdp[4];
int mindp[4];
int maxsave[4], minsave[4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin >> arr[i][j];
        }
    }
    maxsave[1] = arr[1][1];
    maxsave[2] = arr[1][2];
    maxsave[3] = arr[1][3];

    minsave[1] = arr[1][1];
    minsave[2] = arr[1][2];
    minsave[3] = arr[1][3];
    for(int i=2;i<=n;i++){
        maxdp[1] = max(maxsave[1], maxsave[2])+arr[i][1];
        maxdp[2] = max(max(maxsave[1], maxsave[2]), maxsave[3])+arr[i][2];
        maxdp[3] = max(maxsave[2], maxsave[3])+arr[i][3];

        mindp[1] = min(minsave[1], minsave[2])+arr[i][1];
        mindp[2] = min(min(minsave[1], minsave[2]), minsave[3])+arr[i][2];
        mindp[3] = min(minsave[2], minsave[3])+arr[i][3];

        maxsave[1] = maxdp[1]; maxsave[2] = maxdp[2]; maxsave[3] = maxdp[3];
        minsave[1] = mindp[1]; minsave[2] = mindp[2]; minsave[3] = mindp[3];
    }
    cout << max(max(maxsave[1], maxsave[2]), maxsave[3]) << " ";
    cout << min(min(minsave[1], minsave[2]), minsave[3]);
}