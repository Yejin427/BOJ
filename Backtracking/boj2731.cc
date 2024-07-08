#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
long long num, cnt;
void dfs(long long cur){

}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> num;
        long long tmp = num;
        cnt = 1;
        while(tmp / cnt <= 9) cnt *= 10;

        long long start = cbrt(cnt);
        cout << "start: "<<start<<'\n';
        if(num % 10 == 1 || num % 10 == 9) {
            if(start % 10 > num % 10) {
                dfs(start + (10 + start % 10 - num % 10));
            } else {
                dfs(start + (num % 10 - start % 10));
            }
        }
        else if(num % 10 == 3) {
            if(start % 10 > 7) {
                dfs(start + (10 + start % 10 - 7));
            } else {
                dfs(start + (7 - start % 10));
            }
        }
        else {
            
        }
    }
}