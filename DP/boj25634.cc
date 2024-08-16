#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[200001];
int sum, maxi;
int main(){
    int n; cin >> n;
    int minInput = 10000;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        minInput = min(minInput, arr[i]);
    }
    int tmp = 0;
    for(int i=1;i<=n;i++) {
        int light; cin >> light;
        if(!light) {
            tmp += arr[i];
        } else {
            tmp -= arr[i];
            sum += arr[i];
        }
        if(tmp < 0) tmp = 0;
        maxi = max(maxi, tmp);
    }
    if(maxi==0) cout << sum - minInput;
    else cout << sum + maxi;
}