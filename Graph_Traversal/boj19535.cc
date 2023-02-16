#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> tree[300001];
long long child[300001];
long long depth[300001];
bool visited[300001];
long long D, G;
void childcnt(int root){
    child[root] = 0;
    for(auto& c: tree[root]){
        if(child[c] == -1){
            childcnt(c);
            child[root]++;
        }
    }
}
void traverse(int root){
    visited[root] = true;
    long long ch = child[root];
    if(ch >= 1){
        long long childhap = 0;
        for(auto& c: tree[root]){
            if(!visited[c]){
                if(child[c] >= 2){
                    G += child[c] * (child[c]-1) / 2;
                }
                childhap += child[c];
            }
        }
        if(ch >= 2){
            D += childhap * (ch - 1);
            if(ch >= 3){
                G += ch * (ch-1) * (ch-2) / 6;
            }
        }
        
    }
    for(auto& c: tree[root]){
        if(!visited[c]) traverse(c);
    }
}
void depthchk(int root, int d){
    visited[root] = true;
    depth[root] = d;
    for(auto& c: tree[root]){
        if(!visited[c]){
            depthchk(c, d+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n-1;i++){
        int a,b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    memset(child, -1, sizeof(child));
    childcnt(1);
    traverse(1);
    memset(visited, false, sizeof(visited));
    depthchk(1, 1);

    for(int i=1;i<=n;i++){
        if(depth[i] >= 4) D++;
    }
    if(D > G * 3) cout << "D";
    else if(D < G * 3) cout << "G";
    else cout << "DUDUDUNGA";
}