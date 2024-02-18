#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll arr[5001];
int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    ll ans = 5e9;
    ll l1 = 0, l2 = 0, l3 = 0;
    for(int i=0;i<n-2;i++){
        int left = i+1, right = n-1;
        while(left < right){
            ll val = arr[i] + arr[left] + arr[right];
            if(abs(val) < ans){
                ans = abs(val);
                l1 = arr[i], l2 = arr[left], l3 = arr[right];
            }
            if(val < 0) left++;
            else right--;
        }
    }
    cout << l1<<' '<<l2<<' '<<l3;
}