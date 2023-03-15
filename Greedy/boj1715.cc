#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int card[100001];
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> card[i];
    if(n == 1){
        cout << "0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        pq.push(card[i]);
    }
    int ans = 0;
    while(!pq.empty()){
        int f = pq.top();
        pq.pop();
        int s = pq.top(); pq.pop();
        int hap = f+s;
        ans += hap;
        if(!pq.empty()) pq.push(hap);
    }
    cout << ans;
} 