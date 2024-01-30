#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> v;
int main() {
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    if(v.size() == 1) {
        cout << abs(v[0]);
        return 0;
    }
    int minus = 0; int size = v.size();
    
    int last = 0, ans = 0;
    if(abs(v[0]) > abs(v[v.size()-1])) {
        last = v[0];
        //cout << "last: "<<last<<"\n";
        int idx = 0;
        for(; idx<size; idx+=m) {
            if(v[idx] > 0) break;
            ans += abs(2 * v[idx]);
        }
        ans += last;
        
        for(idx = size-1;idx >= 0 && v[idx] > 0;idx-=m) {
            ans += (2 * v[idx]);
        }
    } 
    else {
        last = v[v.size()-1];
        //cout << "last: "<<last<<"\n";
        for(int idx = size-1; idx >= 0 && v[idx] > 0; idx-=m) {
            ans += (2 * v[idx]);
        }
        ans -= last;

        for(int idx = 0; v[idx] < 0; idx+=m) {
            ans += abs(2 * v[idx]);
        }
    }
    cout << ans;
}