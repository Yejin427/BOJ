#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    string change = t;

    string rev = s;
    reverse(rev.begin(), rev.end());

    bool end = true;
    while(1){
        if(change.length() <= s.length()){
            if(end){
                if(change.compare(s) == 0){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            else{
                if(change.compare(rev) == 0){
                    cout << "1";
                }
                else{
                    cout << "0";
                }
            }
            break;
        }
        char c;
        if(end){
            c = change[change.size() - 1];
            change.erase(change.size() - 1);
        }
        else {
            c = change[0];
            change.erase(0, 1);
        }
        if(c == 'B') end = !end;
    }
}