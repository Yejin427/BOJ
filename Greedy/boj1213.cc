#include<iostream>
#include<string>
#include<vector>
using namespace std;
int alpha[27];
vector<char> v;
int main(){
    string str; cin >> str;
    for(int i=0;i<str.length();i++){
        alpha[str[i]-'A']++;
    }
    int holsoo = 0;
    for(int i=0;i<26;i++){
        if(alpha[i] % 2 == 1){
            holsoo++;
            if(holsoo > 1) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    char hol = 0;
    for(int i=0;i<26;i++){
        if(alpha[i] > 0){
            for(int j=1;j<=alpha[i] / 2;j++){
                v.push_back('A'+i);
            }
            if(alpha[i] % 2 == 1) hol = 'A'+i;
        }
    }
    for(int i=0;i<v.size();i++) cout << v[i];
    if(hol) cout << hol;
    for(int i=v.size()-1;i>=0;i--) cout << v[i];
}