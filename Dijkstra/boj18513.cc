#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

typedef pair<double, double> p;
vector<p> points;
priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
double edge[111][111];
double ans[111];
double dist(p p1, p p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
int main() {
    p start, dest;
    cin >> start.first >> start.second >> dest.first >> dest.second;
    int n; cin >> n;    //100이하
    points.push_back(start);
    for(int i=1;i<=n;i++) {
        double x, y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    points.push_back(dest);
    
    for(int i=0;i<=n+1;i++) {
        edge[0][i] = dist(points[0], points[i]) / 5;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n+1;j++) {
            edge[i][j] = min(dist(points[i], points[j]) / 5, 2 + abs(dist(points[i], points[j])-50) / 5);
        }
    }
    // for(int i=0;i<=n+1;i++) {
    //     for(int j=0;j<=n+1;j++) {
    //         cout << edge[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i=0;i<=n+1;i++) ans[i] = -1;
    pq.push({0, 0});
    while(!pq.empty()) {
        double dis = pq.top().first;
        int idx = pq.top().second;
        // cout << "idx: " << idx<< " dist: "<<dis<<'\n';
        pq.pop();
        if(ans[idx] != -1) continue;
        ans[idx] = dis;
        if(idx == n+1) break;
        for(int i=1;i<=n+1;i++) {
            if(ans[i] != -1) continue;
            // cout << "edge: "<<edge[idx][i]<<'\n';
            pq.push({dis + edge[idx][i], i});
        }
    }
    cout << fixed;
    cout.precision(6);
    cout << ans[n+1];
}