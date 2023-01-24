#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>> s;
int merge(pair<int,int> top, pair<int,int> last){
    if(abs(top.second - last.first) == 1) return 1;
    if(abs(top.second - last.second) == 1) return 2;
    if(abs(top.first - last.first) == 1) return 3;
    if(abs(top.first - last.second) == 1) return 4;
    return 0;
}
int main(){
    int n; cin >> n;
    int fs = 0; int se = 0;
    for(int i=1;i<=n;i++){
        int num; cin >> num;
        if(s.empty()){
            s.push({num,num});
        }
        else{
            if(num == s.top().second + 1 || num == s.top().second - 1){
                s.top().second = num;
            }
            else{   //push
                fs = s.top().first;
                se = s.top().second;
                s.push({num,num});
            }
            while(s.size() > 1 && merge(s.top(), {fs,se})){   //전에 꺼와 합침 pop
                int value = merge(s.top(), {fs, se});
                int push1,push2;
                if(value == 1){
                    push1 = s.top().first;
                    push2 = se;
                }
                else if(value == 2){
                    push1 = s.top().first;
                    push2 = fs;
                }
                else if(value == 3){
                    push1 = s.top().second;
                    push2 = se;
                }
                else{
                    push1 = s.top().second;
                    push2 = fs;
                }
                s.pop();s.pop();
                if(!s.empty()){
                    fs = s.top().first;
                    se = s.top().second;
                }
                s.push({push1, push2});
            }
        }
    }
    if(s.size() == 1){
        cout << "YES";
    }
    else cout << "NO";
}