#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
    int b,c,d,a1,a2,e1,e2; 
    cin >> b >> c >> d;
    cin >> a1 >> a2 >> e1 >> e2;

    long long ans = 0;
    for(int i = 1; i <= 1000000; i++) {
        if(a2 * i - c * a1 <= 0) continue;
        if(e2 * i >= c * e1) break;
        ans += ((b*i-1)/c - b*a1/a2) * ((d*e1-1)/e2 - d*i/c);
    }
    
    cout << ans;
}