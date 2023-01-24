#include<bits/stdc++.h>
using namespace std;
bool sosu(int n){
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    while(cin >> num && num != 0){
        bool flag = false;
        for(int i = 2; i <= num / 2; i++){  
            if(sosu(i) && sosu(num - i)){
                cout << num <<" = "<<i<<" + "<<num - i<<'\n';
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "Goldbach's conujecture is wrong."<<"\n";
        }
    }
}