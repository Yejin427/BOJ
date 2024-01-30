#include<iostream>
#include<string>
#include<stack>
#include<deque>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        stack<char> buf;
        deque<char> ans;
        for(char c: s) {
            if(c == '>') {
                if(buf.size()) {
                    ans.push_back(buf.top());
                    buf.pop();
                }
            }
            else if(c == '<') {
                if(ans.size()) {
                    buf.push(ans.back());
                    ans.pop_back();
                }
            }
            else if(c == '-') {
                if(ans.size()) ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }
        while(buf.size()) {
            ans.push_back(buf.top());
            buf.pop();
        }
        for(char c: ans) cout << c;
        cout << '\n';
    }
}