#include<iostream>
#include<algorithm>
using namespace std;

int arr[250001];
int sum[250001];
int main() {
    int n,x; cin >> n >> x;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int ans = 0, cnt = 0;
    for(int i=x;i<=n;i++) {
        if(sum[i] - sum[i-x] > ans) {
            ans = sum[i] - sum[i-x];
            cnt = 1;
        }
        else if(sum[i] - sum[i-x] == ans) {
            cnt++;
        }
    }
    if(ans) cout << ans << '\n' << cnt;
    else cout << "SAD";
}