#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[50010];
int main(){
    int d,n,m; cin >> d >> n >> m;
    int l = d, r = d;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    arr[n+1] = d;
    sort(arr, arr+n+2);
    for(int i=1;i<=n+1;i++) {
        l = min(l, arr[i]-arr[i-1]);
    }
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        int last = arr[0], cnt = 0;
        for(int i=1;i<=n+1;i++){
            if(arr[i] - last < mid) {
                cnt++;
            } else {
                last = arr[i];
            }
        }
        if(cnt <= m) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}