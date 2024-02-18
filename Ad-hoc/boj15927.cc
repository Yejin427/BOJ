#include<iostream>
#include<string>
using namespace std;
int main(){
    string str; cin >> str;
    bool same = true;
    for(int i=0;i<str.size()/2;i++){
        if(str[i] != str[str.size() - i - 1]){
            cout << str.length();
            return 0;
        }
        else if(str[i] != str[i+1]) same = false;
    }
    if(same) cout << -1;
    else cout << str.length() - 1;
}