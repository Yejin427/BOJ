#include<iostream>
#include<vector>
using namespace std;
int main(){
    bool visited[4][4];
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout << visited[i][j];
        }
    }
}