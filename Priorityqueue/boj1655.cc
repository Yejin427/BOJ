#include<bits/stdc++.h>
using namespace std;
priority_queue<int> maxhp;
priority_queue<int, vector<int>, greater<int>> minhp;
int arr[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    
    for(int i=1;i<=n;i++){
        if(i == 1){
            maxhp.push(arr[1]);
        }
        else{
            if(arr[i] > maxhp.top()){
                minhp.push(arr[i]);
            }
            else maxhp.push(arr[i]);
            if(minhp.size() - maxhp.size() == 2){
                int top = minhp.top();
                minhp.pop();
                maxhp.push(top);
            }
            else if(maxhp.size() - minhp.size() == 2){
                int top = maxhp.top();
                maxhp.pop();
                minhp.push(top);
            }
        }
        if(minhp.size() == maxhp.size()) cout << maxhp.top() << '\n';
        else{
            if(minhp.size() > maxhp.size()) cout << minhp.top() <<'\n';
            else cout << maxhp.top() << '\n';
        }
    }
}