#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int color[51];

int main() {
    int m; cin >> m;
    int total = 0;
    for(int i=1;i<=m;i++) {
        cin >> color[i];
        total += color[i];
    }
    int k; cin >> k;
    double ans = 0.0;
    for(int i=1;i<=m;i++) {
        int tmp = total;
        double prob = 1;
        for(int j=1;j<=k;j++) {
            prob *= (double)color[i]--/(double)tmp--;
        }
        ans += prob;
    }
    
    cout << fixed;
    cout.precision(10);
    cout << ans;
}