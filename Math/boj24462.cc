#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int t[1001], k[1001], ans; 
int gcd(int a, int b){
    int tmp, n;
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0){
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d; cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> t[i] >> k[i];
    }
    int s1 = 0, s2 = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ni = d / k[i] - ceil((double)t[i] / (double)k[i]) + 1;
            //cout << "ni: "<<ni<<'\n';
            int nu = d / k[j] - ceil((double)t[j] / (double)k[j]) + 1;
            //cout << "nu: "<<nu<<'\n';
            //lcm자릿수 판정
            int GCD = gcd(k[i], k[j]);
            int ki = k[i], kj = k[j];
            int jar = 0;
            while(ki / 10){
                jar++;
                ki /= 10;
            }
            while(kj / 10){
                jar++;
                kj /= 10;
            }
            while(GCD / 10){
                jar--;
                GCD /= 10;
            }
            int nl;
            //cout << jar <<'\n';
            if(jar > 9){
                if(t[i] == 0 && t[j] == 0) nl = 1;
                else nl = 0;
            }
            else{
                int lcm = k[i] / gcd(k[i], k[j]) * k[j];
                nl = d / lcm - ceil((double)max(t[i], t[j]) / (double)lcm) + 1;
            }
            if(ans < ni + nu - nl){
                ans = ni + nu - nl;
                s1 = i; s2 = j;
            }
        }
    }
    cout << s1 << " " << s2 <<'\n';
    cout << ans;
}