#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cut[10001];
int cl[10002];
int main(){
    int l,k,c; cin >> l >> k >> c;
    for(int i=0;i<k;i++) cin >> cut[i];
    cut[k] = l;

    sort(cut, cut+k);
    cl[0] = cut[0];
    for(int i=1;i<=k;i++){
        cl[i] = cut[i] - cut[i-1];
    }
    int left = 1, right = l, ans = 0, firstcut = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        int sum = 0, ct = 0, p = 0;
        for(int i = k; i >= 0; i--){
            if(cl[i] > mid){
                ct = c+1;
                break;
            }
            if(sum + cl[i] > mid){
                sum = 0;
                ct++;
                p = i;
            }
            sum += cl[i];
        }
        if(ct > c){
            left = mid + 1;
        }
        else{
            right = mid - 1;
            ans = mid;
            firstcut = (ct == c) ? cut[p] : cut[0];
        }
    }
    cout << ans<<" "<<firstcut;
}