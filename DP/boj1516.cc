#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[501];
int m[501];
int order[501];
int ans[501];
int main() {
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> m[i];

        int idx;
        while(cin >> idx && idx != -1) {
            v[idx].push_back(i);
            order[i]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(order[i] == 0) {
            ans[i] = m[i];
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int nxt: v[front]) {
            order[nxt]--;
            ans[nxt] = max(ans[nxt], ans[front] + m[nxt]);
            
            if(order[nxt] == 0) q.push(nxt);
        }
    }
    for(int i=1;i<=n;i++) {
        cout << ans[i] << '\n';
    }
}