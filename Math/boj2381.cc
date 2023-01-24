#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> plus;
    vector<int> minus;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        plus.push_back(x+y);
        minus.push_back(x-y);
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    cout << max(plus[n-1] - plus[0], minus[n-1]-minus[0]);
}