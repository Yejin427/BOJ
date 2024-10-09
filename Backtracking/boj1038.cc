#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt;
long long ans = -1;
void btrk(long long num, int cur) {
    if(cur == 0) {
        if (cnt == n) ans = num;
        cnt++;
        return;
    }
    long long last = num % 10;
    if(num == 0) last = 10;
    for(int i=0;i<last;i++) {
        if(num == 0 && i == 0) continue;
        btrk((num * 10) + i, cur-1);
    }
}
int main(){
    cin >> n;
    for(int i=0;i<=10;i++) {
        btrk(0, i);
    }
    cout << ans;
}