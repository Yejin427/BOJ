#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
using ll = long long;
typedef pair<ll, pair<int,int>> p;
priority_queue<p, vector<p>, greater<p>> pq;
class Point{
public:
    int idx;
    ll x,y,z;
};
bool cmpX(Point p1, Point p2) {
    return p1.x < p2.x;
}
bool cmpY(Point p1, Point p2) {
    return p1.y < p2.y;
}
bool cmpZ(Point p1, Point p2) {
    return p1.z < p2.z;
}

vector<Point> points;
int parent[100001];

int find(int node) {
    if(node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}
void merge(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    parent[root2] = root1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    vector<Point> xsort, ysort, zsort;
    for(int i=0;i<n;i++) {
        Point p;
        p.idx = i;
        cin >> p.x >> p.y >> p.z;
        xsort.push_back(p);
        ysort.push_back(p);
        zsort.push_back(p);
    }
    sort(xsort.begin(), xsort.end(), cmpX);
    sort(ysort.begin(), ysort.end(), cmpY);
    sort(zsort.begin(), zsort.end(), cmpZ);
    for(int i=0;i<n-1;i++) {
        pq.push({xsort[i+1].x - xsort[i].x, {xsort[i].idx, xsort[i+1].idx}});
        pq.push({ysort[i+1].y - ysort[i].y, {ysort[i].idx, ysort[i+1].idx}});
        pq.push({zsort[i+1].z - zsort[i].z, {zsort[i].idx, zsort[i+1].idx}});
    }

    for(int i=0;i<n;i++) {
        parent[i] = i;
    }
    ll ans = 0;
    while(!pq.empty()) {
        p front = pq.top();
        pq.pop();
        
        int node1 = front.second.first;
        int node2 = front.second.second;
        // cout << "dist: "<<front.first<<" node1: "<<node1<<" node2: "<<node2<<'\n';
        if(find(node1) != find(node2)) {
            merge(node1, node2);
            ans += front.first;
        }
    }
    cout << ans;
}