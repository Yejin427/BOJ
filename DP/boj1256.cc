#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int dp[101][101];

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    for(int i=1;i<=100;i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j] > 1e9) dp[i][j] = 1e9;
        }
    }
    
    int anum = n, znum = m;
    if(dp[n][m] < k) {
        cout << -1;
        return 0;
    }

    for(int i=0;i<n+m;i++){
        int a = dp[anum-1][znum];

        if(anum == 0) {
            cout << 'z';
            znum--;
            continue;
        }
        else if(znum == 0){
            cout << 'a';
            anum--;
            continue;
        }
        if(k <= a) {
            cout << 'a';
            anum--;
        }
        else {
            k -= a;
            cout << 'z';
            znum--;
        }
    }
}