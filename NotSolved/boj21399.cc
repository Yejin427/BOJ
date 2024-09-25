#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
ll arr[30001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll sum = 0;
        priority_queue<p> pq;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            pq.push({arr[i], i});
            sum += arr[i];
        }
        vector<int> v;
        ll sale = 0;
        for(int i=0;i<n;i+=3) {
            p top = pq.top();
            sale += top.first;
            pq.pop();
            v.push_back(top.second);
        }
        sort(v.begin(), v.end());
        for(int i=0;i<n;i+=3) {
            int idx = lower_bound(v.begin(), v.end(), i) - v.begin();
            //i/3, idx 비교
            int left = i/3 - idx, right;
            if(i == idx) {
                right = (n-i-1)/3 - (n/3 - idx - 1);
            } else {
                right = (n-i-1)/3 - (n/3 - idx);
            }
        }
    }
    
}