#include<iostream>
#include<string>
using namespace std;
long long arr[1000001];
long long sum[1000001];
const int MOD = 1e9 + 7;
int main(){
    int n; cin >> n;
    arr[0] = 1; sum[0] = 1;
    arr[1] = 2; sum[1] = 3;
    for(int i=2;i<=n;i++) {
        arr[i] = (arr[i-1] * 2 + arr[i-2] * 3 + 2 * sum[i-3]) % MOD;
        sum[i] = (sum[i-1] + arr[i]) % MOD;
    }
    cout << arr[n];
}