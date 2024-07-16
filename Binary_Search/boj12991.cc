#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long A[30001], B[30001];
int main() {
    int n; long long k; cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    for(int i=0;i<n;i++) {
        cin >> B[i];
    }
    sort(A, A+n);
    sort(B, B+n);
    long long l = 1, r = (long long)A[n-1] * B[n-1];
    long long ans;
    while(l <= r) {
        long long mid = (l + r) / 2;
        // cout << "mid: "<<mid<<'\n';
        long long cnt = 0;
        for(int i=0;i<n;i++) {
            int s = 0, e = n-1;
            int idx = 0;
            while(s <= e) {
                int mm = (s + e) / 2;
                if(A[i] * B[mm] <= mid) {
                    idx = mm + 1;
                    s = mm + 1;
                } else {
                    e = mm - 1;
                }
            }
            cnt += idx;
        }
        if(cnt < k) {
            l = mid + 1;
        }
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans;
}