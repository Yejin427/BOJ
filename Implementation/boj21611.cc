#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int arr[50][50], n, m;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int num[50][50];
pair<int,int> idx[2500];    //num의 reverse
vector<int> arrv;
bool visited[50][50];
int ans[4];
void fillNum() {
    int curx = 1, cury = 1;
    int cur = n*n-1;
    for(int i=1;i<=n/2;i++) {
        while(1 <= curx && curx <= n && 1 <= cury && cury <= n && num[curx][cury] == 0) {
            num[curx][cury] = cur;
            cury++; cur--;
        }
        cury--;
        curx++;
        while(1 <= curx && curx <= n && 1 <= cury && cury <= n && num[curx][cury] == 0) {
            num[curx][cury] = cur;
            curx++; cur--;
        }
        curx--;
        cury--;
        while(1 <= curx && curx <= n && 1 <= cury && cury <= n && num[curx][cury] == 0) {
            num[curx][cury] = cur;
            cury--; cur--;
        }
        cury++;
        curx--;
        while(1 <= curx && curx <= n && 1 <= cury && cury <= n && num[curx][cury] == 0) {
            num[curx][cury] = cur;
            curx--; cur--;
        }
        curx++;
        cury++;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            // cout << num[i][j] << ' ';
            idx[num[i][j]] = {i,j};
        }
        // cout << '\n';
    }
    arrv.resize(2500);
    for(int i=1;i<n*n;i++) {
        int r = idx[i].first;
        int c = idx[i].second;
        arrv[i] = arr[r][c];
    }
    // for(int i=1;i<n*n;i++) {
    //     cout << arrv[i] << ' ';
    // }
    // cout << '\n';
}
void fillBlank() {
    int vidx = 1;
    for(int i=1;i<n*n;i++) {
        if(arrv[i] != 0) {
            arr[idx[vidx].first][idx[vidx].second] = arrv[i];
            vidx++;
        }
    }
    for(int i=vidx;i<n*n;i++) arr[idx[i].first][idx[i].second] = 0;
    for(int i=1;i<n*n;i++) {
        int r = idx[i].first;
        int c = idx[i].second;
        arrv[i] = arr[r][c];
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(int i=1;i<n*n;i++) {
    //     cout << arrv[i] << ' ';
    // }
    // cout << '\n';
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }
    fillNum();
    for(int t=1;t<=m;t++) {
        int d,s; cin >> d >> s;
        for(int j=1;j<=s;j++) {
            int r = (n+1)/2 + dx[d-1] * j;
            int c = (n+1)/2 + dy[d-1] * j;
            arrv[num[r][c]] = 0;
        }
        fillBlank();
        while(1) {
            //4개 이상 없애기
            bool end = true;
            int group = 1, gnum = arrv[1];
            if(gnum == 0) break;
            int j = n*n;
            for(int i=2;i<n*n;i++) {
                if(arrv[i] == 0) {
                    j=i;
                    break;
                }
                if(arrv[i] == gnum) {
                    group++;
                } else {
                    if(group >= 4) {
                        end = false;
                        for(int j=i-1;j>=i-group;j--) {
                            arrv[j] = 0;
                        }
                        ans[gnum] += group;
                    }
                    gnum = arrv[i];
                    group = 1;
                }
            }
            if(group >= 4) {
                // cout << "gnum: "<<gnum<<" group: "<<group<<'\n';
                ans[gnum] += group;
                end = false;
                for(int i=1;i<=group;i++) {
                    arrv[j-i] = 0;
                }
            }
            if(end) break;
            //빈곳으로 구슬 이동
            fillBlank();
        }
        //A, B그룹으로 나누기
        vector<int> narrv;
        int group = 1, gnum = arrv[1];
        narrv.push_back(0);
        for(int i=2;i<n*n;i++) {
            if(arrv[i] == 0) break;
            if(arrv[i] == gnum) {
                group++;
            } else {
                narrv.push_back(group);
                narrv.push_back(gnum);
                gnum = arrv[i];
                group = 1;
            }
        }
        if(gnum != 0) {
            narrv.push_back(group);
            narrv.push_back(gnum);
        }
        for(int i=0;i<arrv.size();i++) arrv[i] = 0;
        for(int i=1;i<narrv.size();i++) {
            if(i >= n*n) break;
            arrv[i] = narrv[i];
        }
        int vidx = 1;
        for(int i=1;i<n*n;i++) {
            if(arrv[i] != 0) {
                arr[idx[vidx].first][idx[vidx].second] = arrv[i];
                vidx++;
            }
        }
        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=n;j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    cout << ans[1] + 2 * ans[2] + 3 * ans[3];
}