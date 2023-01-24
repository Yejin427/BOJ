#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool cmp(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<string> s;
    for(int i=1;i<=n;i++){
        string str; cin >> str;
        s.push_back(str);
    }
    sort(s.begin(), s.end(), cmp);
    cout << s[0] <<'\n';
    for(int i=1;i<s.size();i++){
        if(s[i] != s[i-1]) cout << s[i] <<'\n';
    }
}