#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<int> q;
int arr[10001];
int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        q.push(x);
    }
    int ans = 0;
    for(int i=1;i<=m;i++) {
        if(!q.empty()) {
            int top = q.top();
            arr[i] = top;
            q.pop();
        }
        else break;
    }
    //모두 다 0인지 확인
    while(1) {
        bool end = true;
        int curmin = (1 << 16);
        for(int i=1;i<=m;i++) {
            if(arr[i] > 0) {
                end = false;
                curmin = min(arr[i], curmin);
            }
        }
        if(end) break;
        ans += curmin;
        for(int i=1;i<=m;i++) {
            arr[i] -= curmin;
            if(arr[i] == 0) {
                if(!q.empty()) {
                    arr[i] = q.top();
                    q.pop();
                }
            }
        }
    }
    cout << ans;
}