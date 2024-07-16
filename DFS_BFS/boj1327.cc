#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
string s;
int main() {
    int n,k; cin >> n >> k;
    for(int i=0;i<n;i++) {
        char x; cin >> x;
        s += x;
    }
    string sorted = s;
    sort(sorted.begin(), sorted.end());

    queue<pair<string, int>> q;
    map<string, bool> visited;
    q.push({s, 0});
    int ans = -1;
    while(!q.empty()) {
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(str == sorted) {
            ans = cnt;
            break;
        }

        if(!visited.count(str)) {
            visited[str] = true;
            for(int i=0;i<=n-k;i++) {
                string sub = str.substr(i, k);
                reverse(sub.begin(), sub.end());
                q.push({str.substr(0, i) + sub + str.substr(i+k, str.size()), cnt+1});
            }
        }
    }
    cout << ans;
}