#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int arr[100001];
int main(){
    int n; cin >> n;
    long long sum = 0;
    int maxval = 0;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        sum += arr[i];
        maxval = max(maxval, arr[i]);
    }
    if(maxval >= (sum-maxval)) {
        cout << 2 * maxval - sum;
    } else {
        cout << sum % 2;
    }
}