#include<bits/stdc++.h>
using namespace std;
int arr[2001];
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    
    sort(arr, arr+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j == i) continue;
            int idx = lower_bound(arr+j+1, arr+n, arr[i] - arr[j]) - arr;
            if(idx < n && arr[idx] == arr[i] - arr[j]){
                if(idx != i || arr[idx+1] == arr[idx]){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}