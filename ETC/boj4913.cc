#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int sumPrime[1000001];
int sumPerma[1000001];
bool isPrime(int x) {
    if(x == 1) return false;
    for(int i=2;i<=sqrt(x);i++) {
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    vector<pair<int,int>> v;
    while(1){
        int l,u; cin >> l >> u;
        if(l == -1 && u == -1) break;
        
        v.push_back({l, u});
    }
    sumPrime[2] = 1; sumPerma[2] = 1;
    for(int i=3;i<=1000000;i++) {
        if(isPrime(i)) {
            sumPrime[i] = sumPrime[i-1] + 1;
            if(i % 4 == 1) {
                sumPerma[i] = sumPerma[i-1] + 1;
            } else {
                sumPerma[i] = sumPerma[i-1];
            }
        } else {
            sumPrime[i] = sumPrime[i-1];
            sumPerma[i] = sumPerma[i-1];
        }
    }
    for(auto p: v) {
        cout << p.first << ' ' << p.second << ' ' << sumPrime[max(1, p.second)] - sumPrime[max(1, p.first-1)] 
        << ' '<< sumPerma[max(1, p.second)] - sumPerma[max(1, p.first-1)] << '\n';
    }
}