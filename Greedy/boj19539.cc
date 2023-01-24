#include<iostream>
using namespace std;

int arr[100001];
int main(){
    int n, sum = 0; cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 3 != 0) cout <<"NO";
    else{
        int k = sum / 3;
        int l = 0;
        for(int i=1;i<=n;i++){
            l += arr[i] / 2;
        }
        if(k <= l) cout <<"YES";
        else cout <<"NO";
    }
}