#include<iostream>
#include<algorithm>
using namespace std;
int ans[1001];
int main(){
    int a,b,c; cin >> a >> b >> c;
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            int x,y,z; cin >> x >> y >> z;
            ans[i] += (a*x+b*y+c*z);
        }
    }
    int k = 0;
    for(int i=1;i<=n;i++){
        k = max(k, ans[i]);
    }
    cout << k;
}