#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
char str[1000002];
long long k[1000002];
long long ck[1000002];
long long ock[1000002];
long long pw[1000002];
const int MOD = 1'000'000'007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> str[i];
    //for(int i=1;i<=n;i++) cout << str[i] <<" ";
    pw[0] = 1;
    for(int i=1;i<=n;i++) pw[i] = (pw[i-1] * 2) % MOD;
    long long ans = 0;
    for(int i=n;i>=1;i--){
        k[i]=k[i+1];
        ck[i]=ck[i+1];
        ock[i]=ock[i+1];
        if(str[i] == 'K'){
            k[i] = (1 + k[i]) % MOD;
        }
        else if(str[i] == 'C'){
            ck[i] = (k[i] + ck[i]) % MOD;
        }
        else if(str[i] == 'O'){
            ock[i] = (ck[i] + ock[i]) % MOD;
        }
        else if(str[i] == 'R'){
            ans += (ock[i] * pw[i-1]);
            ans %= MOD;
        }
    }
    cout << ans;
}