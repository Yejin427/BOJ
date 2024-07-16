#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> p;
typedef long long ll;
ll a[500010];
ll sum[500010];
vector<int> v;
vector<p> t; 
int main() {
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    int maxE = 0;
    for(int i=1;i<=m;i++) {
        int s,e; cin >> s >> e;
        v.push_back(s); v.push_back(e+1);
        t.push_back({s, 1});
        t.push_back({e+1, -1});
        maxE = max(e, maxE); 
    }
    sort(a+1, a+n+1);
    sort(t.begin(), t.end());
    for(int i=1;i<=n;i++) {
        sum[i] = sum[i-1] + a[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int cnt = 0;
    ll least = 0, best = 0; 
    for(int i=0,j=0;i<v.size()-1;i++) {
        int add = 0, rmv = 0;
        while(j < t.size() && t[j].first <= v[i]) {
            if(t[j].second == 1) add++;
            else rmv++;
            j++;
        }
        cnt += add - rmv;

        ll dt = v[i+1] - v[i];
        if(cnt) {
            least += dt * sum[cnt];
            best += dt * (sum[n] - (n-cnt >= 0 ? sum[n-cnt] : 0));
        }
    }
    cout << least << ' '<<best;
}