#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int p[10001], cur;
bool finished[10001];
vector<int> v[10001];
vector<vector<int>> ans;
stack<int> s;
int findScc(int x) {
    p[x] = cur++;
    s.push(x);

    int parent = p[x];
    for(int i=0;i<v[x].size();i++) {
        int nxt = v[x][i];
        if(p[nxt] == 0) {
            parent = min(parent, findScc(nxt));
        }
        else if(!finished[nxt]) {
            parent = min(parent, p[nxt]);
        }
    }
    if(parent == p[x]) {
        vector<int> scc;
        while(x) {
            int y = s.top();
            s.pop();
            scc.push_back(y);
            finished[y] = true;
            if(y == x) break;
        }
        sort(scc.begin(), scc.end());
        ans.push_back(scc);
    }
    return parent;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k; cin >> n >> k;
    while(k--) {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
    cur = 1;
    for(int i=1;i<=n;i++) {
        if(p[i] == 0) findScc(i);
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++) {
            cout << ans[i][j] << ' ';
        }
        cout << "-1\n";
    }
}