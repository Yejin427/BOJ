#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool bit[1000001][10];
long long cnt[1024];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k; cin >> n >> k;
    vector<string> s;
    for(int i=1;i<=n;i++) {
        string str; cin >> str;
        s.push_back(str);
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            bit[i][s[i][j]-'0'] = true;
        }
    }
    
    for(int i=0;i<n;i++) {
        int val = 0;
        for(int j=0;j<10;j++) {
            if(bit[i][j]) val += (1 << j);
        }
        cnt[val]++;
    }
    long long ans = 0;
    for(int i=0;i<1024;i++) {
        if(!cnt[i]) continue;
        for(int j=0;j<=i;j++) {
            if(!cnt[j]) continue;
            int val = i | j;
            int onecnt = 0;
            while(val != 0) {
                onecnt += val % 2;
                val /= 2;
            }
            if(onecnt == k) {
                if(i == j) {
                    if(cnt[i] > 1) ans += cnt[i] * (cnt[i] - 1) / 2;
                }
                else ans += (cnt[i] * cnt[j]);
            }
        }
    }
    cout << ans;
}