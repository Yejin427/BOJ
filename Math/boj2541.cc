#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int a,b; cin >> a >> b;
    for(int i=1;i<=5;i++) {
        int x,y; cin >> x >> y;
        if(a < b) {
            if(y <= x) cout << "N\n";
            else {
                int op = b-a;
                while(op % 2 == 0) op /= 2;
                if((y-x) % op == 0) cout <<"Y\n";
                else cout << "N\n";
            }
        }
        else if(a > b) {
            if(x <= y) cout << "N\n";
            else {
                int op = a-b;
                while(op % 2 == 0) op /= 2;
                if((x-y) % op == 0) cout << "Y\n";
                else cout << "N\n";
            }
        }
        else {
            if(x == y) cout << "Y\n";
            else cout << "N\n";
        }
        
    }
}