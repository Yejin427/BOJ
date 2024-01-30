#include<iostream>
#include<algorithm>
#include<cstring>
int arr[1001];
bool chk[1001];
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        int idx = 1;
        int ans = 0;
        while(idx <= n) {
            if(chk[idx]) {
                idx++;
                continue;
            }
            chk[idx] = true;
            int start = arr[idx];
            while(!chk[start]) {
                chk[start] = true;
                start = arr[start];
            }
            ans++;
            idx++;
        }
        cout << ans << '\n';
        memset(chk, false, sizeof(chk));
    }
}