#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int arr[101][101];
int main() {
    int n; cin >> n;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }

    int l = 0, r = 200;
    while(l <= r) {
        int mid = (l + r) / 2;
        
        
    }
}