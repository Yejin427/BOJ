#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--) {
        string s; int k;
        cin >> s >> k;
        vector<int> alpha[26];
        for(int i=0;i<s.length();i++) {
            alpha[s[i]-'a'].push_back(i);
        }
        int mini = s.length(), maxi = 0;
        if(k == 1) {
            cout << 1 << ' '<<1<<'\n';
            continue;
        }
        for(int i=0;i<26;i++) {
            int size = alpha[i].size();
            if(size >= k) {
                for(int j=0;j<size-k+1;j++) {
                    mini = min(alpha[i][j+k-1]-alpha[i][j] + 1, mini);
                    maxi = max(alpha[i][j+k-1]-alpha[i][j] + 1, maxi);
                }
            }
        }
        if(maxi == 0) cout << -1 << '\n';
        else cout << mini << ' ' << maxi << '\n';
    }
}