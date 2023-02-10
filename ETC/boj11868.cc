#include<iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int grundy; cin >> grundy;
    for(int i=1;i<n;i++){
        int rock; cin >> rock;
        grundy ^= rock;
    }
    cout << ((grundy == 0) ? "cubelover" : "koosaga");
}