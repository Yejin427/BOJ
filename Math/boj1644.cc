#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool notprime[4000001];
vector<int> sum;

int main() {
    int n; cin >> n;

    for(int i=2;i<=sqrt(n);i++){
        for(int j=2*i;j<=n;j+=i){
            notprime[j] = 1;
        }
    }

    int psum = 0;
    sum.push_back(0);
    for(int i=2;i<=n;i++){
        if(!notprime[i]){
            psum += i;
            sum.push_back(psum);
        }
    }

    int left = 0, right = 0;

    int ans = 0;
    while(left <= right && right < sum.size()) {
        if(sum[right] - sum[left] > n) {
            left++;
            //cout << "left: "<<left<<'\n';
        }
        else {
            if(sum[right] - sum[left] == n) {
                ans++;
            }
            right++;
            //cout << "right: "<<right<<'\n';
        }
    }
    cout << ans;
}