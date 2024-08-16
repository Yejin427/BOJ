#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        double total = 0;
        for(int i=1;i<=n;i++) {
            double x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(y1 / x1 == y2 / x2) continue;
            double rad = acos((x1*x2+y1*y2) / (sqrt(x1*x1+y1*y1) * sqrt(x2*x2+y2*y2))) / (2 * M_PI);
            total += rad;
        }
        // cout << "total: "<<total<<'\n';
        cout << fixed;
        cout.precision(5);
        cout << total << '\n';
    }
}