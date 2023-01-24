#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> v;
vector<pair<int,int>> vy;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
        vy.push_back({x,y});
    }
    sort(v.begin(), v.end());
    sort(vy.begin(), vy.end(), cmp);
    int ans = 1e9;
    for(int xmin = 0; xmin < n; xmin++){
        for(int xmax = xmin; xmax < n; xmax++){
            int xleft = v[xmin].first - 1;
            int xright = v[xmax].first + 1;
            int ymin = 0, ymax = 0, yl = 0, yr = 0;
            while(ymin <= ymax && ymax < n){
                int yleft = vy[ymin].second - 1;
                int yright = vy[ymax].second + 1;
                int num = 0;
                for(int i=0;i<n;i++){
                    if(vy[i].second >= yright) break;   //y 좌표 순으로 정렬함
                    if(yleft < vy[i].second && vy[i].second < yright && xleft < vy[i].first && vy[i].first < xright) num++;
                }
                if(num < n/2) ymax++;
                else{
                    int square = (xright - xleft) * (yright - yleft);
                    if(square != 0) ans = min(ans, square);
                    ymin++;
                }
            }
            //넓이 구하기
        }
    }
    cout << ans;
}