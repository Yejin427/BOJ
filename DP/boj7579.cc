#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int dp[101][10001];
int m[101], c[101];
int costsum;
int main(){
    int N,M; cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> m[i];
    }
    for(int i=1;i<=N;i++){
        cin >> c[i];
        costsum += c[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<=costsum;j++){
            if(j - c[i] < 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-c[i]] + m[i], dp[i-1][j]);
            }
        }
    }
    for(int i=0;i<=costsum;i++){
        if(dp[N][i] >= M){
            cout << i;
            break;
        }
    }
}