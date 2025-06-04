#include<iostream>
#include<algorithm>
using namespace std;
int arr[15][15];
int tmp[15][15], n, m;
int fold(int a[][15]) {
    int copy[15][15];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            copy[i][j] = a[i][j];
        }
    }
    //열로 자르기
    int newarr[15][15];
    for(int r=1;r<n;r++) {
        if(r * 2>n) {
            
            for(int i=r*2+1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                    newarr[i][j] = copy[n+1-i][j];
                }
            }
            for(int i=r;i>=1;i--) {
                for(int j=1;j<=m;j++) {
                    copy[i][j] = copy[]
                }
            }
        }
        else {
            for(int i=1;i<=n;i++) {

            }
        }

    }
}
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
        }
    }
    fold(arr);
}