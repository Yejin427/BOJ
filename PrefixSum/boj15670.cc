#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100001];
int sum[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    sum[1] = 1;
    for(int i=2;i<=n;i++) {
        if(arr[i] > arr[i-1]) {
            sum[i] = sum[i-1];
        }
        else {
            sum[i] = sum[i-1] + 1;
        }
    }
    while(m--) {
        int l, r; cin >> l >> r;
        int ans = r - l + 1 - (sum[r] - sum[l]);
        //l, r+1비교 r, l-1비교
        if(r < n) {
            if(arr[l] < arr[r+1]) {
                ans += sum[n] - sum[r+1];
            } else {
                ans += sum[n] - sum[r+1] + 1;
            }
        }
        if(l > 1) {
            if(arr[l-1] < arr[r]) {
                ans += sum[l-1] - 1;
            } else {
                ans += sum[l-1];
            }
        }
        cout << ans << '\n';
    }
}