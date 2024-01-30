#include<iostream>
#include<string>
#include<sstream>
#include<deque>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string cmd, num; 
        cin >> cmd;
        int n; cin >> n;
        cin >> num;
        num = num.substr(1, num.length()-2);
        stringstream sstream(num);

        string push;
        deque<string> nums;
        while(getline(sstream, push, ',')){
            nums.push_back(push);
        }

        bool left = true;
        bool error = false;
        for(char c: cmd){
            if(c == 'R'){
                left = !left;
            }
            else if(c == 'D'){
                if(!nums.size()){
                    error = true;
                    break;
                }
                if(left){
                    nums.pop_front();
                }
                else{
                    nums.pop_back();
                }
            }
        }
        if(error){
            cout << "error\n";
            continue;
        }
        cout << '[';
        while(nums.size()){
            if(left){
                cout << nums.front();
                nums.pop_front();
            }
            else{
                cout << nums.back();
                nums.pop_back();
            }
            if(nums.size()) cout << ',';
        }
        cout << "]\n";
    }
}