#include<iostream>
#include<string>
using namespace std;
int main(){
    int turn = 0;
    bool left = false,right = false,center = false;
    bool finish = false;
    int num = 0;    //움직인 칸수
    while(turn < 10){
        string s; cin >> s;
        int move;
        if(s == "1111") move = 5;
        else if(s == "0000") move = 4;
        else{
            turn++;
            if(s == "0111" || s == "1011" || s == "1101" || s == "1110") move = 1;
            else if(s == "1000" || s == "0100" || s == "0010" || s == "0001") move = 3;
            else move = 2;
        }
        //move position
        if(num < 5){
            num += move;
            if(num == 5) right = true;
        }
        else if(!right && num > 5 && num < 10){
            num += move;
            if(num == 10){
                left = true;
            }
        }
        else if(!right && left){
            num += move;
            if(num > 16){
                finish = true;
            }
        }
        else if(right && num >= 5 && num < 8){
            num += move;
            if(num == 8) center = true;
        }
        else if(right && center){
            num += move;
            if(num > 11){
                finish = true;
            }
        }
        else if(right && !center){
            num += move;
            if(num > 16){
                finish = true;
            }
        }
        else{
            num += move;
            if(num > 20){
                finish = true;
            }
        }
    }
    if(finish) cout << "WIN";
    else cout << "LOSE";
}