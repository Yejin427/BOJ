#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    double x,y,d,t;
    cin >> x >> y >> d >> t;
    double length = sqrt(x*x + y*y);
    double time = 0;
    cout << fixed;
    cout.precision(10);
    if(d < t) cout << length;
    else{
        int jumpnum = length / d;
        double ret = length - jumpnum * d;
        
        if(length < d){
            time = min({length, 2.0 * t, t + d - ret});
        }
        else{
            time = min({length, jumpnum * t + ret, (jumpnum+1.0) * t});
        }
        cout << time;
    }
}