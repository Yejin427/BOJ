#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int arr[11][11], n, ans;
int dist[11][11], prev[11][11];
void dfs(int bit, int prev, int sum) {
    if(bit == (1<<n)-1) {
        ans = min(ans, sum);
        return;
    }
    for(int i=0;i<n;i++) {
        if((bit & (1 << i)) == 0) dfs(bit | (1 << i), i, sum + dist[prev][i]);
    }
}
int main(){
    int k; cin >> n >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
            dist[i][j] = arr[i][j];
        }
    }
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    ans = 1e6;
    dfs(0, k, 0);
    cout << ans;
}