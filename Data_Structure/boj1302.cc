#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
map<string, int> m;
int main() {
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(m.find(s) == m.end()) m[s] = 0;
        else m[s]++;
    }

    int max = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(max < it->second) {
            max = it->second;
        } 
    }
    vector<string> v;
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second == max) v.push_back(it->first);
    }
    sort(v.begin(), v.end());
    cout << v[0];
}