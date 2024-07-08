#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,pair<int,int>> p;
bool visited[1501][1501];

int main() {
    int n; cin >> n;
    string s; cin >> s;
    queue<p> q;
    q.push({0, {0, 3*n-1}});
    visited[0][3*n-1] = true;
    int ans = 0;
    while(!q.empty()) {
        p front = q.front();
        q.pop();
        int eat = front.first;
        int start = front.second.first;
        int end = front.second.second;
        ans = max(eat, ans);
        if(start > end) continue;

        if(eat % 3 == 0) {
            if(s[start] == 'B' && !visited[start+1][end]) {
                visited[start+1][end] = true;
                q.push({eat+1, {start+1, end}});
            }
            if(s[end] == 'B' && !visited[start][end-1]) {
                visited[start][end-1] = true;
                q.push({eat+1, {start, end-1}});
            }
        }
        else if(eat % 3 == 1) {
            if(s[start] == 'L' && !visited[start+1][end]) {
                visited[start+1][end] = true;
                q.push({eat+1, {start+1, end}});
            }
            if(s[end] == 'L' && !visited[start][end-1]) {
                visited[start][end-1] = true;
                q.push({eat+1, {start, end-1}});
            }
        }
        else {
            if(s[start] == 'D' && !visited[start+1][end]) {
                visited[start+1][end] = true;
                q.push({eat+1, {start+1, end}});
            }
            if(s[end] == 'D' && !visited[start][end-1]) {
                visited[start][end-1] = true;
                q.push({eat+1, {start, end-1}});
            }
        }
    }
    cout << ans;
}