#include<iostream>
char arr[501][501];
int dx[4]={0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r,c; cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(arr[i][j] == 'W'){
                for(int k=0;k<4;k++){
                    int nx = i+dx[k]; int ny = j+dy[k];
                    if(nx < 1 || nx > r || ny < 1 || ny > c) continue;
                    if(arr[nx][ny] == 'S'){
                        cout <<"0";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "1\n";
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(arr[i][j] != 'S' && arr[i][j] != 'W') cout <<'D';
            else cout << arr[i][j];
        }
        cout <<'\n';
    }
}