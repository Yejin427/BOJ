#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
string arr[1001];
int n, m;
int dx[6] = {0, 1, 0, -1, 1, 1}, dy[6] = {1, 0, -1, 0, 1, -1};
bool visited[1001][1001];
int ans, maxmul;
string nums[10] = {
    "**** ** ** ****", //0
	"**  *  *  * ***", //1
	"**   * * *  ***", //2
	"***  * **  ****", //3
	"  * *** ****  *", //4
	"****  **   ****", //5
	"*  *  **** ****", //6
	"***  * * *  *  ", //7
	"**** ***** ****", //8
	"**** ****  *  *"  //9
};
void bfs(int row, int col) {
    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = true;
    int minx = 1001, miny = 1001, maxx = 0, maxy = 0;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        maxx = max(maxx, r); minx = min(minx, r);
        maxy = max(maxy, c); miny = min(miny, c);
        q.pop();
        for(int i=0;i<6;i++) {
            int nr = r + dx[i]; int nc = c + dy[i];
            if(nr < 0 || nr > n-1 || nc < 0 || nc > m-1 || arr[nr][nc] != '*') continue; 
            if(!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }
    int mul = (maxx - minx + 1) / 5;
    if(maxmul < mul) {
        maxmul = mul;
        string cur = "";
        for(int i=minx;i<=maxx;i+=mul) {
            for(int j=miny;j<=maxy;j+=mul) {
                cur += arr[i][j];
            }
        }
        for(int i=0;i<10;i++) {
            if(cur == nums[i]) {
                ans = i;
                break;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin.ignore();
    for(int i=0;i<n;i++) {
        getline(cin, arr[i]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == '*' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }
    cout << ans;
}