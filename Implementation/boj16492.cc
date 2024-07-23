#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
using namespace std;

map<char, string> m;
string del1, del2, target;
int main() {
    bool end = false;
    while(!end) {
        string query;
        getline(cin, query);
        if(query.substr(0, 3) == "gen") {
            m[query[5]] = query.substr(10);
        }
        else if(query.substr(0, 3) == "del") {
            if(del1 == "") del1 = query.substr(5);
            else del2 = query.substr(5);
        }
        else if(query.substr(0, 6) == "target") {
            target = query.substr(8);
            end = true;
        }
    }
    string str = "A";
    for(int i=1;i<=10;i++) {
        //gen
        string tmp = "";
        for(int j=0;j<str.length();j++) {
            if(m.find(str[j]) != m.end()) {
                tmp += m[str[j]];
            } else {
                tmp += str[j];
            }
        }
        // cout<< "after gen: "<<tmp<<'\n';
        //del
        vector<int> del(tmp.size(), 0);
        if(del1.length() && del1.length() <= tmp.length()) {
            int len = del1.length();
            for(int j=0;j<=tmp.length()-len;j++) {
                if(tmp.substr(j, len) == del1) {
                    for(int k=j;k<j+len;k++) {
                        del[k] = 1;
                    }
                }
            }
        }
        if(del2.length() && del2.length() <= tmp.length()) {
            int len = del2.length();
            for(int j=0;j<=tmp.length()-len;j++) {
                if(tmp.substr(j, len) == del2) {
                    for(int k=j;k<j+len;k++) {
                        del[k] = 1;
                    }
                }
            }
        }
        string tmp_ = "";
        for(int j=0;j<tmp.length();j++) {
            if(!del[j]) {
                tmp_ += tmp[j];
            }
        }
        str = tmp_;
        if(str == target) {
            cout << "O";
            return 0;
        }
    }
    cout << "X";
}