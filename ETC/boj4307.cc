#include<iostream>
using namespace std;
int ant[100001];
int main(){
    int t; cin >> t;
    while(t--){
        int l,n; cin >> l >> n;
        for(int i=1;i<=n;i++){
            cin >> ant[i];
        }
        int fast = 0;
        int slow = 0;
        for(int i=1;i<=n;i++){
            fast = max(fast, min(ant[i], l-ant[i]));
            slow = max(slow, max(ant[i], l-ant[i]));
        }
        cout << fast << ' ' << slow << '\n';
    }
    return 0;
}