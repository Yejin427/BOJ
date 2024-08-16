#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[52];
int main() {
    int n,m,l; cin >> n >> m >> l;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    arr[n+1] = l;
    sort(arr+1, arr+n+1);
    int le = 1, r = 0;
    for(int i=1;i<=n+1;i++) {
        r = max(arr[i] - arr[i-1], r);
    }
    int ans = 0;
    while(le <= r) {
        int mid = (le + r) / 2;
        int cnt = 0;
        for(int i=1;i<=n+1;i++) {
            int dis = arr[i] - arr[i-1];
            cnt += (dis-1) / mid;
        }
        if(cnt > m) {
            le = mid + 1;
        }
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans;
}