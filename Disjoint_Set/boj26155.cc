#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int parent[100001], ans[100001];
typedef struct pipe{
    int a,b;
    double p;
    pipe(int a, int b, double p): a(a), b(b), p(p) {}
    bool operator<(const pipe& P) const{
        if(p == P.p){
            if(b == P.b) return a < P.a;
            return b < P.b;
        }
        return p > P.p;
    }
}pipe;
vector<pair<double, int>> prob;
vector<pipe> pipes;
int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int a, int b){
    int ra = find(a);
    int rb = find(b);
    parent[rb] = ra;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;

    for(int i=1;i<=m;i++){
        int a,b; double p; 
        cin >> a >> b >> p;
        pipes.push_back(pipe(a,b,p));
    }
    sort(pipes.begin(), pipes.end());   //확률 순으로 내림차순 정렬
    int q; cin >> q;
    for(int i=1;i<=q;i++){
        double pp; cin >> pp;
        prob.push_back({pp, i});
    }
    sort(prob.begin(), prob.end(), greater<pair<double, int>>());
    
    int i = 0; int set = n;
    for(auto& query: prob){
        while(i < pipes.size()){
            if(pipes[i].p < query.first) break;
            else {
                if(find(pipes[i].a) != find(pipes[i].b)){
                    merge(pipes[i].a, pipes[i].b);
                    set--;
                }
                i++;
            }
        }
        ans[query.second] = set;
    }
    for(int i=1;i<=q;i++) cout << ans[i] << '\n';
}