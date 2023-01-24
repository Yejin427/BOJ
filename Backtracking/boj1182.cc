#include<bits/stdc++.h>
using namespace std;
int arr[21], n, s, cnt;
void dfs(int x, int tmp){
    tmp += arr[x];
    if(tmp == s && x != 0) cnt++;
    if(x == n) return;
    for(int i=x+1; i<=n;i++){
        dfs(i, tmp);
    }
}
int main(){
    cin >> n >> s;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << cnt;
}