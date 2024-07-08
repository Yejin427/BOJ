#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

vector<string> v;
bool cmp(string a, string b) {
    if(a.length() == b.length()) {
        return a > b;
    } 
    else {
        string nna = a + b;
        string nnb = b + a;
        return nna > nnb;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    string ans = "";
    sort(v.begin(), v.end(), cmp);
    for(string num: v) {
        ans += num;
    }
    bool zero = true;
    for(char c: ans) {
        if(c != '0') {
            zero = false;
            break;
        }
    }
    if(zero) cout << 0;
    else cout << ans;
}