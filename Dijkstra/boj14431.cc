#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
using pi = pair<int,int>;  //distance, index
priority_queue<pi, vector<pi>, greater<pi>> pq;
int visited[4001];
typedef struct point{
    int x,y;
}point;
bool prime(int num){
    if(num == 1) return false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    point sosu, a;
    cin >> sosu.x >> sosu.y >> a.x >> a.y;
    int n; cin >> n;
    vector<point> town;

    town.push_back(sosu);
    for(int i=1;i<=n;i++){
        int x,y; cin >> x >> y;
        town.push_back({x,y});
    }
    town.push_back(a);
    memset(visited, -1, sizeof(visited));

    pq.push({0, 0});
    while(!pq.empty()){
        int dis = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(visited[idx] != -1) continue;
        visited[idx] = dis;
        int x = town[idx].x, y = town[idx].y;
        for(int i = 0; i < town.size();i++){
            int distance = (int)sqrt(pow(town[i].x - x, 2) + pow(town[i].y - y, 2));
            //cout << "distance: "<<distance<<'\n';
            if(visited[i] == -1 && prime(distance)){
                pq.push({dis + distance, i});
            }
        }
    }
    cout << visited[town.size()-1];
}