#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<pair<pair<int,int>, pair<int,int>>, int> pii;
char arr[12][12];
bool visited[12][12][12][12];
pair<int,int> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main(){
    int n,m; cin >> n >> m;
    int holex = -1, holey = -1;
    int rx = -1, ry = -1, bx = -1, by = -1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'O') {
                holex = i, holey = j;
            } else if(arr[i][j] == 'R') {
                rx = i, ry = j;
            } else if(arr[i][j] == 'B') {
                bx = i, by = j;
            }
        }
    }
    queue<pii> q;
    q.push({{{rx, ry}, {bx, by}}, 0});
    int ans = -1;
    while(!q.empty()) {
        pair<int,int> red = q.front().first.first, blue = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(holex == blue.first && holey == blue.second) {
            continue;
        }
        else if(holex == red.first && holey == red.second) {
            ans = cnt;
            break;
        }
        if(cnt == 10) continue;
        //왼쪽 무빙
        int lftr = red.second, lftb = blue.second, rgtr = red.second, rgtb = blue.second;
        if(red.second < blue.second) {
            //왼쪽 무빙   
            while(1) {
                if(arr[red.first][lftr] == '#') {
                    lftr++;
                    break;
                }
                if(arr[red.first][lftr] == 'O') break;
                lftr--;
            }
            while(1) {
                if(arr[blue.first][lftb] == 'O') break;
                if(arr[blue.first][lftb] == '#' || (red.first == blue.first && lftb == lftr)) {
                    lftb++;
                    break;
                }
                lftb--;
            }
            //오른쪽 무빙 -> blue먼저
            while(1) {
                if(arr[blue.first][rgtb] == '#') {
                    rgtb--;
                    break;
                }
                if(arr[blue.first][rgtb] == 'O') break;
                rgtb++;
            }
            while(1) {
                if(arr[red.first][rgtr] == 'O') break;
                if(arr[red.first][rgtr] == '#' || (red.first == blue.first && rgtb == rgtr)) {
                    rgtr--;
                    break;
                }
                rgtr++;
            }            
        } else {
            while(1) {
                if(arr[blue.first][lftb] == '#') {
                    lftb++;
                    break;
                }
                if(arr[blue.first][lftb] == 'O') break;
                lftb--;
            }
            while(1) {
                if(arr[red.first][lftr] == 'O') break;
                if(arr[red.first][lftr] == '#' || (red.first == blue.first && lftb == lftr)) {
                    lftr++;
                    break;
                }
                lftr--;
            }
            //오른쪽 무빙
            while(1) {
                if(arr[red.first][rgtr] == '#') {
                    rgtr--;
                    break;
                }
                if(arr[red.first][rgtr] == 'O') break;
                rgtr++;
            }
            while(1) {
                if(arr[blue.first][rgtb] == 'O') break;
                if(arr[blue.first][rgtb] == '#' || (red.first == blue.first && rgtb == rgtr)) {
                    rgtb--;
                    break;
                }
                rgtb++;
            }
        }
        if((lftb != blue.second || lftr != red.second) && !visited[red.first][lftr][blue.first][lftb]) { //변화가 있으면
            visited[red.first][lftr][blue.first][lftb] = true;
            q.push({{{red.first, lftr}, {blue.first, lftb}}, cnt+1});
        }
        if((rgtb != blue.second || rgtr != red.second) && !visited[red.first][rgtr][blue.first][rgtb]) {
            visited[red.first][rgtr][blue.first][rgtb] = true;
            q.push({{{red.first, rgtr}, {blue.first, rgtb}}, cnt+1});
        }
        lftr = red.first, lftb = blue.first, rgtr = red.first, rgtb = blue.first;
        if(red.first < blue.first) {
            //위로 무빙
            while(1) {
                if(arr[lftr][red.second] == '#') {
                    lftr++;
                    break;
                }
                if(arr[lftr][red.second] == 'O') break;
                lftr--;
            }
            while(1) {
                if(arr[lftb][blue.second] == 'O') break;
                if(arr[lftb][blue.second] == '#' || (red.second == blue.second && lftb == lftr)) {
                    lftb++;
                    break;
                }
                lftb--;
            }
            //아래로 무빙
            while(1) {
                if(arr[rgtb][blue.second] == '#') {
                    rgtb--;
                    break;
                }
                if(arr[rgtb][blue.second] == 'O') break;
                rgtb++;
            }
            while(1) {
                if(arr[rgtr][red.second] == 'O') break;
                if(arr[rgtr][red.second] == '#' || (red.second == blue.second && rgtb == rgtr)) {
                    rgtr--;
                    break;
                }
                rgtr++;
            }
        } else {
            //위로 무빙
            while(1) {
                if(arr[lftb][blue.second] == '#') {
                    lftb++;
                    break;
                }
                if(arr[lftb][blue.second] == 'O') break;
                lftb--;
            }
            while(1) {
                if(arr[lftr][red.second] == 'O') break;
                if(arr[lftr][red.second] == '#' || (red.second == blue.second && lftb == lftr)) {
                    lftr++;
                    break;
                }
                lftr--;
            }
            //아래로 무빙
            while(1) {
                if(arr[rgtr][red.second] == '#') {
                    rgtr--;
                    break;
                }
                if(arr[rgtr][red.second] == 'O') break;
                rgtr++;
            }
            while(1) {
                if(arr[rgtb][blue.second] == 'O') break;
                if(arr[rgtb][blue.second] == '#' || (red.second == blue.second && rgtb == rgtr)) {
                    rgtb--;
                    break;
                }
                rgtb++;
            }
        }
        if((lftb != blue.first || lftr != red.first) && !visited[lftr][red.second][lftb][blue.second]) { //변화가 있으면
            visited[lftr][red.second][lftb][blue.second] = true;
            q.push({{{lftr, red.second}, {lftb, blue.second}}, cnt+1});
        }
        if((rgtb != blue.first || rgtr != red.first) && !visited[rgtr][red.second][rgtb][blue.second]) {
            visited[rgtr][red.second][rgtb][blue.second] = true;
            q.push({{{rgtr, red.second}, {rgtb, blue.second}}, cnt+1});
        }
    }
    cout << ans;
}