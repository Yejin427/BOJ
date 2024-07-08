#include<iostream>
#include<vector>
using namespace std;
int s[300][300];
int e[300][300];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> s[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> e[i][j];
        }
    }
    
}