#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int dp[101][2][20];    //현재 번호, 마법 몇번째

int main(){
    string m, devil, angel; 
    cin >> m >> devil >> angel;

    int length = devil.length();

    for(int i=0;i<length;i++){
        if(devil[i] == m[0]) dp[i+1][0][1] = dp[i][0][1] + 1;
        else dp[i+1][0][1] = dp[i][0][1];
        if(angel[i] == m[0]) dp[i+1][1][1] = dp[i][1][1] + 1;
        else dp[i+1][1][1] = dp[i][1][1];
    }

    for(int i=2;i<=m.length();i++){
        for(int j = 1; j <= length; j++){

            if(devil[j-1] == m[i-1]){
                // if(dp[j-1][0][i]){
                //     dp[j][0][i] = dp[j-1][0][i] + 1;
                // }
                // else dp[j][0][i] = dp[j-1][1][i-1];
                dp[j][0][i] = dp[j-1][1][i-1] + dp[j-1][0][i];
            }
            else{
                dp[j][0][i] = dp[j-1][0][i];
            }

            if(angel[j-1] == m[i-1]){
                // if(dp[j-1][1][i]) dp[j][1][i] = dp[j-1][1][i] + 1;
                // else dp[j][1][i] = dp[j-1][0][i-1];
                dp[j][1][i] = dp[j-1][0][i-1] + dp[j-1][1][i];
            }
            else{
                dp[j][1][i] = dp[j-1][1][i];
            }
        }
    }
    
    cout << dp[length][0][m.length()] + dp[length][1][m.length()];
}