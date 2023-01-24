#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
using pi = pair<long long,long long>;

pi point;
long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
    long long a = x1 * y2 + x2 * y3 + x3 * y1;
    long long b = y1 * x2 + y2 * x3 + y3 * x1;
    return a - b;
}
bool cmp(pi a, pi b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y > b.y;
}
bool ccwsort(pi a, pi b){
    long long cw = ccw(point.x, point.y, a.x, a.y, b.x, b.y);
    if(cw == 0){
        if (a.y == b.y) return a.x < b.x;
		else return a.y > b.y;
    }
    return cw < 0;
}
int main(){
    int p; cin >> p;
    while(p--){
        vector<pi> arr;
        vector<pi> convex;

        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            long long a,b; cin >> a >> b;
            arr.push_back({a,b});
        }
        sort(arr.begin(), arr.end(), cmp);

        point = arr.front();
        arr.erase(arr.begin());

        sort(arr.begin(), arr.end(), ccwsort);
        convex.push_back(point);

        for(auto& p: arr){
            while(convex.size() >= 2){
                pi p2 = convex.back();
                convex.erase(convex.end() - 1);
                pi p1 = convex.back();
                if(ccw(p1.x, p1.y, p2.x, p2.y, p.x, p.y) < 0){
                    convex.push_back(p2);
                    break;
                }
            }
            convex.push_back(p);
        }

        cout << convex.size() << '\n';
        for(auto& p: convex){
            cout << p.x <<" "<< p.y <<'\n';
        }
    }
}