#include<iostream>
#include<cstring>
using namespace std;
int arr[100001];
int card[500001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> arr[i];

    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        //cout << "MID: "<<mid<<'\n';
        int cnt = 0, idx = 1;
        while(idx <= n){
            int left = idx;
            int right = idx + mid - 1;
            if(right > n) break;
            int save = 0;
            for(int k = left; k <= right; k++){
                //cout << "K: "<<k<<" card[arr[k]]: "<<card[arr[k]]<<'\n';
                if(card[arr[k]] >= left && card[arr[k]] != k) {
                    save = card[arr[k]];
                    break;
                }
                card[arr[k]] = k;
            }
            if(!save){
                idx += mid;
                cnt++;
            }
            else idx = save + 1;
        }
        //cout << "cnt: "<<cnt<<'\n';
        if(cnt >= m){
            l = mid + 1;
            ans = mid;
        }
        else{
            r = mid - 1;
        }
        memset(card, 0, sizeof(card));
    }
    cout << ans;
}