#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n; cin >> n;
    int num = n;
    while(num){
        if(num == 1) break;
        bool prime = true;
        for(int i=2;i<=sqrt(num);i++){
            if(num % i == 0){
                cout << i <<'\n';
                num /= i;
                prime = false;
                break;
            }
        }
        if(prime){
            cout << num<<'\n';
            break;
        }
    }
}