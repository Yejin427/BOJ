#include<iostream>
using namespace std;
int main(){
    int e,s,m; cin >> e >> s >> m;
    int e1 = 1, s1 = 1, m1 = 1, ans = 1;
    while(!(e1 == e && s1 == s && m1 == m)){
        e1++; s1++; m1++; ans++;
        if(e1 == 16) e1 = 1;
        if(s1 == 29) s1 = 1;
        if(m1 == 20) m1 = 1;
    }
    cout << ans;
}