#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n,k; cin >> n >> k;
    string num; cin >> num;
    deque<char> d;
    for(int i=0;i<num.length();i++){
        while(k > 0 && !d.empty() && d.back() < num[i]){
            d.pop_back();
            k--;
        }
        d.push_back(num[i]);
    }
    for(int i=0;i<d.size();i++){
        cout << d[i];
    }
    cout << '\n';
}