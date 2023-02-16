#include<iostream>
#include<cmath> 
using namespace std;
int main(){
    int n,k; cin >> n >> k;
    if(k > (n / 2) * (n - n / 2)) cout << -1;
    else if(n > k){
        for(int i=1;i<=n;i++){
            if(i == n-k) cout << 'A';
            else cout << 'B';
        }
    }
    else{
        int order = 2;
        while(ceil((double)k / order) > n - order){
            order++;
        }
        if(k % order == 0){
            for(int i=1;i<=n-order-k/order;i++) cout << 'B';
            for(int i=1;i<=order;i++) cout << 'A';
            for(int i=1;i<=k/order;i++) cout << 'B';
        }
        else{
            for(int i=1;i<=n-order-k/order-1;i++) cout << 'B';
            for(int i=1;i<=k%order;i++) cout << 'A';
            cout <<'B';
            for(int i=1;i<=order-k%order;i++) cout << 'A';
            for(int i=1;i<=k/order;i++) cout << 'B';
        }
    }
}