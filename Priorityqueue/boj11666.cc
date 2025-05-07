#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int arr[300001][2];
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int,int>> v;
int main(){
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        int s, e; cin >> s >> e;
        v.push_back({s,e});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(auto p: v) {
        if(pq.empty() || p.first < pq.top()) {  //새 워크스페이스 할당
            pq.push(p.first+p.second);
            ans++;
        }
        else if(pq.top() + m >= p.first) {  //기존 것 재사용, 잠금해제X
            pq.pop();
            pq.push(p.first+p.second);
        }
        else {  //가장 오래 전에 사용한 것도 잠금해제 필요 
            while(!pq.empty() && pq.top() + m < p.first) {
                pq.pop();
            }
            if(pq.empty()) {
                pq.push(p.first + p.second);
                ans++;
            } else {
                pq.pop();
                pq.push(p.first + p.second);
            }
        }
    }
    cout << n-ans;
}