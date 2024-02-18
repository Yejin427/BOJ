#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int d[1001], arr[1001];
int dp[1001];
vector<int> v[1001];

int main(){
    int t; cin >> t;
    while(t--){
        int d[1001], arr[1001]={0};
        int dp[1001]={0};
        vector<int> v[1001];
        int n,k; cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> d[i];
        for(int i=1;i<=k;i++){
            int a,b; cin >> a >> b;
            v[a].push_back(b);
            arr[b]++;
        }
        int w; cin >> w;
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(arr[i] == 0) q.push(i);
        }
        while(arr[w] > 0){
            int front = q.front();
            q.pop();
            for(int next: v[front]){
                dp[next] = max(dp[next], dp[front] + d[front]);
                if(--arr[next] == 0) q.push(next);
            }
        }
        cout << dp[w] + d[w]<<'\n';
    }
}