#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2e9
using namespace std;

class segtree{
public:
    int size;
    vector<int> tree;
    segtree(int n){
        for(size = 1; size < n; size *= 2);
        tree.resize(2 * size);
    }
    void update(int pos, int start, int end, int node, int num){
        if(end < node || node < start) return;
        if(start == node && node == end) {
            tree[pos] = num;
            return;
        }
        int mid = (start + end) / 2;
        update(pos * 2, start, mid, node, num);
        update(pos * 2 + 1, mid+1, end, node, num);
        tree[pos] = min(tree[pos*2], tree[pos*2+1]);
    }
    int query(int pos, int start, int end, int left, int right){
        if(end < left || right < start) return INF;
        if(left <= start && end <= right) return tree[pos];
        int mid = (start + end) / 2;
        return min(query(pos * 2, start, mid, left, right), query(pos * 2 + 1, mid + 1, end, left, right));
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    segtree seg(n);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        seg.update(1, 1, seg.size, i, x);
    }
    int m; cin >> m;
    for(int i=1;i<=m;i++){
        int com, idx, x, a,b;
        cin >> com;
        if(com == 1){
            cin >> idx >> x;
            seg.update(1, 1, seg.size, idx, x);
        }
        if(com == 2){
            cin >> a >> b;
            cout << seg.query(1, 1, seg.size, a, b) << '\n';
        }
    }
}
