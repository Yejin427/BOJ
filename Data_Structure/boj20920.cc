#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> mp;
vector<string> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        string s; cin >> s;
        if(s.length() >= m) {
            if(mp.find(s) == mp.end()) {
                mp[s] = 1;
                v.push_back(s);
            } else {
                mp[s]++;
            }
        }
    }
    sort(v.begin(), v.end(), [&](string a, string b){
        if(mp[a] == mp[b]) {
            if(a.length() == b.length()) {
                return a < b;
            }
            return a.length() > b.length();
        }
        return mp[a] > mp[b];
    });
    for(string str: v) cout << str << '\n';
}