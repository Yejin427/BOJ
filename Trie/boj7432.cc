#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

class Trie{
public:
    map<string, Trie*> node;

    void insert(vector<string>& v, int idx) {
        if(idx == v.size()) return;
        //아직 없음
        if(node.find(v[idx]) == node.end()) {
            Trie* trie = new Trie;
            node.insert({v[idx], trie});
        }
        node[v[idx]]->insert(v, idx+1);

    }

    void dfs(int depth) {
        vector<pair<string, Trie*>> tmpv(node.begin(), node.end());
        sort(tmpv.begin(), tmpv.end());

        for(auto& ch: tmpv){
            for(int i=1;i<=depth;i++) {
                cout << ' ';
            }
            cout << ch.first <<'\n';
            ch.second->dfs(depth+1);
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    Trie* root = new Trie;

    for(int i=1;i<=n;i++) {
        string path; cin >> path;

        stringstream sstream(path);
        string word;
        vector<string> v;
        while(getline(sstream, word, '\\')) {
            v.push_back(word);
        }

        root->insert(v, 0);
    }
    root->dfs(0);
}