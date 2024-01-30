#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;
int main() {
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        string s1, s2;
        cin >> s1 >> s2;

        vector<int> a;
        vector<int> b;
        for(int i=0;i<s1.length();i++) {
            if(s1[i] == 'b') a.push_back(i);
            if(s2[i] == 'b') b.push_back(i);
        }
        int ans = 0;
        for(int i=0;i<a.size();i++){
            ans += abs(a[i] - b[i]);
        }
        cout << ans << '\n';
    }
}