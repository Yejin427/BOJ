#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
char arr[100][100];
char ans[101][101];
int cnt = 0;
void func(int s, int e, int depth) {
    if(s >= e || depth == 7) return;
    cnt = max(cnt, depth);
    int mid = (s + e) / 2;
    for(int i=s;i<=mid;i++) {
        ans[depth][i] = 'A';
    }
    for(int i=mid+1;i<=e;i++) {
        ans[depth][i] = 'B';
    }
    func(s, mid, depth+1);
    func(mid+1, e, depth+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    func(1, n, 0);
    for(int i=0;i<=cnt;i++) {
        for(int j=1;j<=n;j++) {
            if(ans[i][j] == 0) {
                if(j % 2 == 1) ans[i][j] = 'A';
                else ans[i][j] = 'B';
            }
            cout << ans[i][j];
        }
        cout << '\n';
    }
    int idx = 0;
    while(cnt != 6) {
        for(int i=0;i<n;i++) {
            if(i == idx) cout << 'B';
            else cout << 'A';
        }
        cout << '\n';
        idx = (idx+1)%n;
        cnt++;
    }
}