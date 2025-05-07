#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];
int f[1000001];
int nxt[1000001];
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        f[arr[i]]++;
    }

    int curmax = 0;
    //int front[1000001];
    for(int i=n;i>=1;i--) {
        if(curmax < f[arr[i]]) {
            curmax = f[arr[i]];
            nxt[i] = -1;
        } else {
            if(f[arr[i+1]] > f[arr[i]]) {
                nxt[i] = i+1;
            } else {
                int cur = i+1;
                while(cur != -1 && f[arr[cur]] <= f[arr[i]]) {
                    cur = nxt[cur];
                }
                nxt[i] = cur;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(nxt[i] != -1) cout << arr[nxt[i]] << ' ';
        else cout << -1 << ' ';
    }
}