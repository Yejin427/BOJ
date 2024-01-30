#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
    int a,b; cin >> a >> b;
    int ans = 0;
    bool flag = true;
    while(b > a){
        if(b % 10 == 1){
            b /= 10;
        }
        else if(b % 2 == 0){
            b /= 2;
        }
        else{
            flag = false;
            break;
        }
        ans++;
    }
    if(a == b) cout << ans+1;
    else cout << -1;
}