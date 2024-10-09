#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
using pii = pair<pair<int,int>, int>;    //위치, 방향
pair<int,int> arr[21][21];  //idx, 남은시간
int dir[401][4][4];  //idx, 현재 dir, 다음 dir
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};   //상, 하, 좌, 우 순
vector<pii> shark;  
int redun[21][21];  //상어 겹침 체크
int main(){
    int n,m,k; 
    cin >> n >> m >> k;
    shark.resize(m+1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            arr[i][j] = {0, 0};    //초기화
            cin >> arr[i][j].first;
            if(arr[i][j].first) {
                arr[i][j].second = k;
                shark[arr[i][j].first].first = {i,j};
            }
        }
    }
    for(int i=1;i<=m;i++) {
        int direction; cin >> direction;
        shark[i].second = --direction;
    }

    for(int i=1;i<=m;i++) {
        for(int j=0;j<4;j++) {
            for(int k=0;k<4;k++) {
                cin >> dir[i][j][k];
                dir[i][j][k]--;
            }
        }
    }
    int ans = 1;
    while(ans <= 1000) {
        //상어 이동
        for(int s=1;s<shark.size();s++) {
            int r = shark[s].first.first;
            int c = shark[s].first.second;
            int d = shark[s].second;
            // cout << "shark : "<<s<<' '<<r<<", "<<c<<' '<<d<<'\n';
            if(r == -1 && c == -1) continue;
            vector<int> tmp;
            for(int i=0;i<4;i++) {
                //갈 수 있는 곳 삽입
                if(r + dx[i] < 1 || r + dx[i] > n || c + dy[i] < 1 || c + dy[i] > n) continue;
                if(arr[r + dx[i]][c + dy[i]].first == s || arr[r + dx[i]][c + dy[i]].second == 0) {
                    tmp.push_back(i);
                }
            }
            if(tmp.size() == 1) {
                shark[s].first = make_pair(r + dx[tmp[0]], c + dy[tmp[0]]);
                shark[s].second = tmp[0];
            } else {
                bool flag = false;
                for(int i=0;i<4;i++) {
                    if(flag) break;
                    for(int nxtdir: tmp) {
                        if(arr[r + dx[nxtdir]][c + dy[nxtdir]].second > 0) continue;
                        if(dir[s][d][i] == nxtdir) {
                            shark[s] = {{r + dx[nxtdir], c + dy[nxtdir]}, nxtdir};
                            // cout << "shark: "<<s<<" nxtdir: "<<nxtdir<<'\n';
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag) {
                    for(int i=0;i<4;i++) {
                        if(flag) break;
                        for(int nxtdir: tmp) {
                            if(dir[s][d][i] == nxtdir) {
                                shark[s] = {{r + dx[nxtdir], c + dy[nxtdir]}, nxtdir};
                                // cout << "shark: "<<s<<" nxtdir: "<<nxtdir<<'\n';
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        //시간 감소
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(arr[i][j].second) {
                    arr[i][j].second--;
                }
            }
        }
        //중복 유무 -> 잡아먹음
        for(int s=1;s<shark.size();s++) {
            if(shark[s].first == make_pair(-1, -1)) continue;
            int chkidx = redun[shark[s].first.first][shark[s].first.second];
            if(chkidx == 0) {
                redun[shark[s].first.first][shark[s].first.second] = s;
                arr[shark[s].first.first][shark[s].first.second] = {s,k};
            } else {
                if(s < chkidx) {    //s우선
                    redun[shark[s].first.first][shark[s].first.second] = s;
                    shark[chkidx] = {{-1,-1},-1};
                    arr[shark[s].first.first][shark[s].first.second] = {s,k};
                } else {    //이전 chkidx우선
                    shark[s] = {{-1,-1},-1};
                }
            }
        }
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout << arr[i][j].first << ' '<<arr[i][j].second << ' ';
        //     }
        //     cout << '\n';
        // }
        //남은 상어 체크
        int left = m;
        for(int s=1;s<shark.size();s++) {
            if(shark[s].first == make_pair(-1, -1)) left--;
        }
        if(left == 1) break;
        ans++;
        memset(redun, 0, sizeof(redun));
    }
    if(ans > 1000) cout << -1;
    else cout << ans;
}