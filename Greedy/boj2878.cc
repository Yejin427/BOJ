#include<bits/stdc++.h>
using namespace std;
unsigned long long arr[100001];
int main(){
    unsigned long long m,n; cin >> m >> n;
    unsigned long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+n);
    unsigned long long nocandy = sum - m; //부족한 개수를 n만큼 나누기

    unsigned long long ans = 0;
    for(int i=0;i<n;i++){
        unsigned long long give = min(nocandy / (n-i), arr[i]);
        ans += give * give;
        nocandy -= give;
    }
    cout << ans;
}