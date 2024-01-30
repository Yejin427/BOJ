#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<cmath>
using namespace std;
int arr[10001];
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> arr[i];
        sort(arr+1, arr+n+1);
        deque<int> d1; deque<int> d2;
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(i % 2 ==1){
                d1.push_back(arr[i]);
            }
            else d2.push_back(arr[i]);
        }
        while(d1.size()){
            int f = d1.front();
            d1.pop_front();
            v.push_back(f);
        }
        while(d2.size()){
            int f = d2.back();
            d2.pop_back();
            v.push_back(f);
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(ans, abs(v[i] - v[i-1]));
        }
        ans = max(v[n-1] - v[0], ans);
        cout << ans << '\n';
    }
}