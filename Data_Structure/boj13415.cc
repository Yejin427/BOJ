#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
int arr[100001];
int sortedarr[100001];

int main(){
    int n; cin >> n;
    int m = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        sortedarr[i] = arr[i];
    }
    int k; cin >> k;
    stack<int> s;
    while(k--){
        int up, down;
        cin >> up >> down;
        m = up;
        if(m <= up){
            while(!s.empty() && abs(s.top()) <= m){
                s.pop();
            }
        }
        s.push(up);
        m = down;
        if(m <= down){
            while(!s.empty() && abs(s.top()) <= m){
                s.pop();
            }
        }
        s.push(-down);
    }
    stack<int> ns;
    while(!s.empty()){
        ns.push(s.top());
        //cout << s.top() <<" ";
        s.pop();
    }
    //cout <<'\n';
    sort(arr+1, arr+abs(ns.top())+1);
    int inc = abs(ns.top()), dec = 1, idx = abs(ns.top());
    while(!ns.empty()){
        int cur = ns.top();
        ns.pop();
        int next = ns.empty() ? 0 : ns.top();
        int length = abs(cur) - abs(next);
        if(cur < 0){
            for(int i=0;i<length;i++) sortedarr[idx--] = arr[dec++];
        }
        else{
            for(int i=0;i<length;i++){
                sortedarr[idx--] = arr[inc--];
            }
        }
    }
    for(int i=1;i<=n;i++) cout << sortedarr[i] << ' ';
}