#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char arr[201][201];
char arr2[201][201];
char arr3[201][201];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
    int r,c,n; cin >> r >> c >> n;
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin >> arr[i][j];
            arr2[i][j] = 'O';
            arr3[i][j] = 'O';
        }
    }
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            if(arr[i][j] == '.') continue;
            cout << "i: "<<i<<"j: "<<j<<'\n';
            arr2[i][j] = '.';
            for(int k=0;k<4;k++) {
                int nr = i + dx[k], nc = j + dy[k];
                if(nr < 1 || nr > r || nc < 1 || nc > c) continue;
                arr2[nr][nc] = '.';
            }
        }
    }
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            if(arr2[i][j] == '.') continue;
            arr3[i][j] = '.';
            for(int k=0;k<4;k++) {
                int nr = i + dx[k], nc = j + dy[k];
                if(nr < 1 || nr > r || nc < 1 || nc > c) continue;
                arr3[nr][nc] = '.';
            }
        }
    }
    if(n % 2 == 0) {
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                cout << 'O';
            }
            cout << '\n';
        }
    }
    else {
        if(n == 1) {
            for(int i=1;i<=r;i++) {
                for(int j=1;j<=c;j++) {
                    cout << arr[i][j];
                }
                cout << '\n';
            }
        }
        else if(n % 4 == 3) {
            for(int i=1;i<=r;i++) {
                for(int j=1;j<=c;j++) {
                    cout << arr2[i][j];
                }
                cout << '\n';
            }
        }
        else {
            char narr[201][201];
            for(int i=1;i<=r;i++) {
                for(int j=1;j<=c;j++) {
                    cout << arr3[i][j];
                }
                cout << '\n';
            }
        }
    }
}