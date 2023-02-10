#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int c[20][20];
int combi(int n, int k){
    if(n == k || k == 0 || n == 1) return 1;
    if(c[n][k] > 0) return c[n][k];
    return c[n][k] = combi(n-1, k-1)+combi(n-1, k);
}
int main(){
    double a,b; cin >> a >> b;
    double ans = 0;
    for(int i=0;i<=18;i++){
        switch(i){
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
            ans += combi(18, i) * pow(a / 100, i) * pow((100-a) / 100, (18-i));
            break;
        default:
            //a가 소수가 아니기 때문에 b가 무조건 소수여야함
            double subans = 0;
            for(int j=1;j<=18;j++){
                switch(j){
                case 2:
                case 3:
                case 5:
                case 7:
                case 11:
                case 13:
                case 17:
                    subans += combi(18, j) * pow(b / 100, j) * pow((100-b) / 100, (18-j));
                    break;
                default:
                    break;
                }
            }
            ans += combi(18, i) * pow(a / 100, i) * pow((100-a) / 100, (18-i)) * subans;
            break;
        }
    }
    cout << fixed;
    cout.precision(7);
    cout << ans;
}