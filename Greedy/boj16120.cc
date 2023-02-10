#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string str; cin >> str;
    if(str == "P") cout << "PPAP";
    else if(str.length() < 4) cout << "NP";
    else{
        int pnum = 0;
        bool np = false;
        for(int i=0;i<str.length();i++){
            if(str[i] == 'P') pnum++;
            else if(str[i] == 'A'){
                if(pnum < 2){
                    np = true;
                    break;
                }
                if(str[i+1] != 'P'){
                    np = true;
                    break;
                }
                pnum -= 2;
            }
            else{
                np = true;
                break;
            }
        }
        if(np || pnum != 1) cout << "NP";
        else cout << "PPAP";
    }
}