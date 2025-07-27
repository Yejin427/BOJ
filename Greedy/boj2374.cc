#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
using ll = long long;
int arr[1001];
int main(){
    int n; cin >> n;
    int maxval = 0;

    stack<int> s;
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        maxval = max(maxval, arr[i]);
        
        if(s.empty()) {
            s.push(arr[i]);
            continue;
        }
        if(s.top() < arr[i]) {
            ll tmp = 0;
            while(!s.empty() && s.top() < arr[i]) {
                int top = s.top();
                s.pop();
                int nxtTop = s.empty() ? arr[i] : min(s.top(), arr[i]);
                tmp += nxtTop - top;
            }
            ans += tmp;
            
        }
        s.push(arr[i]);
    }
    ll tmp = 0;
    while(!s.empty() && s.top() < maxval) {
        int top = s.top();
        s.pop();
        int nxtTop = s.empty() ? maxval : min(s.top(), maxval);
        tmp += nxtTop - top;
    }
    ans += tmp;
    cout << ans;
}