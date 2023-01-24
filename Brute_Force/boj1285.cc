#include<iostream>
#include<algorithm>
using namespace std;
bool arr[21][21];
int n,ans, dp[1000000];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin >> c;
            if(c == 'H') arr[i][j] = true; 
        }
    }
    ans = 1000;
    for(int i=0;i<=(1<<n)-1;i++){
        int ret = 0;
        for(int j=0;j<n;j++){
            int head = 0;
            for(int k=0;k<n;k++){
                if(((1 << k) & i)!= 0){
                    if(!arr[k][j]) head++;
                }
                else{
                    if(arr[k][j]) head++;
                }
            }
            ret += min(head, n-head);
        }
        ans = min(ans, ret);
    }
    
    cout << ans;
}