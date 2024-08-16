#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int arr[100][100];
int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }
    
    int ans = n;
    for(int box = 1; box <= n; box++) {
        int cur = 0;
        map<int, bool> chk;
        for(int i=1;i<=n;i++) {
            if(i == box) continue;
            int cnt = 0, idx = -1;
            for(int j=1;j<=m;j++) {
                if(arr[i][j]){
                    cnt++;
                    idx = j;
                }
            }
            if(cnt == 0) cur++;
            else if(cnt == 1) {
                if(chk.find(idx) == chk.end()) {
                    chk[idx] = true;
                }
            }
        }
        ans = min(ans, n-1-(cur+(int)chk.size()));
    }
    cout << ans;
}