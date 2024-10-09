#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int arr[410][4];
int sorted[410], map[21][21], cnt[21][21];
using pii = pair<pair<int,int>, pair<int,int>>;
int main(){
    int n; cin >> n;
    for(int i=1;i<=n*n;i++) {
        int student; cin >> student;
        sorted[i] = student;
        for(int j=0;j<4;j++) {
            cin >> arr[student][j];
        }
    }
    for(int r=1;r<=n;r++) {
        for(int c=1;c<=n;c++) {
            for(int k=0;k<4;k++) {
                int nr = r + dx[k], nc = c + dy[k];
                if(nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                    cnt[r][c]++;
                }
            }
        }
    }
    for(int i=1;i<=n*n;i++) {
        priority_queue<pii> pq;
        int num = sorted[i];
        //친밀도 계산
        for(int r=1;r<=n;r++) {
            for(int c=1;c<=n;c++) {
                if(map[r][c]) continue;
                int f = 0;
                for(int k=0;k<4;k++) {
                    int nr = r + dx[k], nc = c + dy[k];
                    if(nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                        if(map[nr][nc] == arr[num][0] || map[nr][nc] == arr[num][1] 
                            || map[nr][nc] == arr[num][2] || map[nr][nc] == arr[num][3]) f++;
                    }
                }
                pq.push({{f, cnt[r][c]}, {-r, -c}});
            }
        }
        //가장 우선순위
        pii front = pq.top();
        int r = -front.second.first, c = -front.second.second;
        map[r][c] = num;
        //빈칸 개수 제거
        for(int k=0;k<4;k++) {
            int nxtr = r + dx[k], nxtc = c + dy[k];
            if(nxtr >= 1 && nxtr <= n && nxtc >= 1 && nxtc <= n) cnt[nxtr][nxtc]--;
        }
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int num = map[i][j];
            int f = 0;
            for(int k=0;k<4;k++) {
                int nr = i + dx[k], nc = j + dy[k];
                if(nr >= 1 && nr <= n && nc >= 1 && nc <= n) {
                    if(map[nr][nc] == arr[num][0] || map[nr][nc] == arr[num][1] 
                        || map[nr][nc] == arr[num][2] || map[nr][nc] == arr[num][3]) f++;
                }
            }
            if(f > 0) ans += pow(10, f-1);
        }
    }
    cout << ans;
}