#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
class segtree{
public:
    int size;
    vector<int> v;
    segtree(int n){
        for(size = 1; size < n; size *= 2);
        v.resize(2 * size);
    }
    int init(int node, int start, int end, int m){
        if(start == end){
            if(start <= m) return v[node] = 0;
            else return v[node] = 1;
        }

        int mid = (start + end) / 2;
        return v[node] = init(node * 2, start, mid, m) + init(node * 2 + 1, mid + 1, end, m);
    }
    void update(int node, int start, int end, int idx, int diff){
        if(idx < start || end < idx) return;
        v[node] += diff;
        if(start == end) return;
        int mid = (start+end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
    int sum(int node, int start, int end, int left, int right){
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return v[node];
        int mid = (start + end) / 2;
        return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid+1, end, left, right); 
    }
};
int idx[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        segtree tree(n+m);
        tree.init(1, 1, n+m, m);
        memset(idx, 0, sizeof(idx));
        for(int i=1;i<=n;i++){
            idx[i] = i+m;
        }
        for(int i=1;i<=m;i++){
            int dvd; cin >> dvd;
            int point = idx[dvd];
            cout << tree.sum(1, 1, n+m, 1, point-1)<<' ';
            tree.update(1, 1, n+m, point, -1);
            tree.update(1, 1, n+m, m-i+1, 1);
            idx[dvd] = m-i+1;
        }
    }
}