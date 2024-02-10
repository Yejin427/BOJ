#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;

class Trie {
public:
    map<string, Trie*> m;

    void insert(vector<string>& v, int idx){
        if(idx == v.size()) return;

        if(m.find(v[idx]) == m.end()) {
            Trie* trie = new Trie;
            m.insert({v[idx], trie});
        }

        m[v[idx]]->insert(v, idx+1);
    }

    void dfs(int depth) {
        for(auto& i: m) {
            for(int j=0;j<depth;j++) {
                cout << "--";
            }
            cout << i.first << '\n';
            i.second->dfs(depth+1);
            delete i.second;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    Trie* root = new Trie;

    for(int i=1;i<=n;i++) {
        int num; cin >> num;
        vector<string> v(num);
        for(int j=0;j<num;j++) {
            cin >> v[j];
        }
        root->insert(v, 0);
    }
    root->dfs(0);
    delete root;
    
}