#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<int, bool> m;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q; cin >> n >> q;
    for(int i=1;i<=n;i++) {
        bool b; cin >> b;
        if(b) m[i] = b;
    }
    int pos = 1;
    while(q--) {
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int x; cin >> x;
            if(m[x]) m.erase(x);
            else m[x] = true;
        }
        else if(cmd == 2) {
            int x; cin >> x;
            pos = (pos + x) % n;
            if(pos == 0) pos = n;
        }
        else if(cmd == 3) {
            if(m.size() == 0) cout << "-1\n";
            else {
                auto nxt = m.lower_bound(pos);
                if(nxt == m.end()) {
                    cout << (n - pos) + (*m.begin()).first << '\n';
                } else {
                    cout << (*nxt).first - pos << '\n';
                }
            }
        }
    }
}