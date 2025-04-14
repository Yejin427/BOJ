#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int arr[21][21], n;
bool ans[21], visited[1<<21];
void f(int presentBit) {
    visited[presentBit] = true;
    if(log2(presentBit) == (int)log2(presentBit)) {
        ans[(int)log2(presentBit) + 1] = true;
        return;
    }
    for(int i=0;i<n;i++) {
        if(((1<<i) & presentBit) != 0) {
            //현재 비트를 없앨 수 있나?
            int money = 0;
            for(int j=0;j<n;j++) {
                if(((1<<j) & presentBit) != 0) {
                    money += arr[i][j];
                }   
            }
            if(money > 0 && !visited[presentBit - (1<<i)]) {
                f(presentBit - (1<<i));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> arr[i][j];
            }
        }
        f((1<<n)-1);
        bool flag = false;
        for(int i=1;i<=n;i++) {
            if(ans[i]) {
                cout << i << ' ';
                flag = true;
            }
        }
        if(!flag) cout << 0;
        cout << '\n';
        memset(ans, false, sizeof(ans));
        memset(visited, false, sizeof(visited));
    }
}