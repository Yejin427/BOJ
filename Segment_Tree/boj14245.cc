#include<bits/stdc++.h>
using namespace std;
class segtree{
public:
    int size;
    vector<int> tree;
    vector<int> lazy;
    segtree(int n){
        for(size = 1; size < n; size *= 2);
        tree.resize(2 * size);
        lazy.resize(2 * size);
    }
    void update_lazy(int start, int end, int node){
        if(lazy[node] != 0){
            if((end - start + 1) % 2 == 1){
                tree[node] ^= lazy[node];
            }
            if(start != end){
                lazy[node * 2] ^= lazy[node];
                lazy[node * 2 + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int pos, int start, int end, int left, int right, int diff){
        update_lazy(start, end, pos);
        if(left > end || right < start) return;
        if(left <= start && end <= right){
            lazy[pos] ^= diff;
            update_lazy(start, end, pos);
            return;
        }
        int mid = (start + end) / 2;
        update(pos * 2, start, mid, left, right, diff);
        update(pos * 2 + 1, mid + 1, end, left, right, diff);
        tree[pos] = tree[pos * 2] ^ tree[pos * 2 + 1];
    }
    int query(int pos, int start, int end, int left, int right){
        update_lazy(start, end, pos);
        if(left > end || right < start) return 0;
        if(left <= start && end <= right) return tree[pos];
        int mid = (start + end) / 2;
        return query(pos * 2, start, mid, left, right) ^ query(pos * 2 + 1, mid + 1, end, left, right);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n;
    segtree seg(n);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        seg.update(1, 1, n, i, i, x);
    }
    cin >> m;
    while(m--){
        int t; cin >> t;
        if(t == 1){
            int a,b,c; cin >> a >> b >> c;
            seg.update(1, 1, n, a + 1, b + 1, c);
        }
        else{
            int a; cin >> a;
            cout << seg.query(1, 1, n, a + 1, a + 1) << "\n";
        }
    }
}