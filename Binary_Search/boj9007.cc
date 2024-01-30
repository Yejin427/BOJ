#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int k,n; cin >> k >> n;
        int arr[4][1001];
        for(int i=0;i<4;i++){
            for(int j=1;j<=n;j++){
                cin >> arr[i][j];
            }
        }

        vector<int> v1; vector<int> v2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v1.push_back({arr[0][i] + arr[1][j]});
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v2.push_back({arr[2][i] + arr[3][j]});
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int ans = 1e8;
        for(int i=0;i<v1.size();i++){
            int idx = lower_bound(v2.begin(), v2.end(), k-v1[i]) - v2.begin();
            if(idx == 0){
                if(abs(v2[idx] + v1[i] - k) < abs(k-ans))
                    ans = v2[idx] + v1[i];
                continue;
            }
            if(abs(v2[idx] + v1[i] - k) < abs(v2[idx-1] + v1[i] - k)){  //양수 선택
                if(abs(v2[idx] + v1[i] - k) < abs(k-ans))
                    ans = v2[idx] + v1[i];
            }
            else{   //음수 선택
                if(abs(v2[idx-1] + v1[i] - k) < abs(k-ans)){    
                    ans = v2[idx-1] + v1[i];
                }
                if(abs(v2[idx-1] + v1[i] - k) == abs(k-ans) && ans-k > 0){  //음수
                    ans = v2[idx-1] + v1[i];
                }
            }
        }
        cout << ans<<'\n';
    }
}