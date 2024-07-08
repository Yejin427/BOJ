#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
bool g[100001];
bool h[100001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        string str; cin >> str;
        vector<char> ans(100001);
        for(int i = 0; i < n; i++) {
            if(str[i] == 'G') g[i] = true;
            else h[i] = true;
        }

        int tmp = -1, prev = -1, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!g[i]) continue;
            if(tmp == -1) { //g가 처음 나옴
                tmp = i; 
                prev = i;
                continue;
            }
            if(i <= tmp + 2 * k) {
                prev = i;
            } else {
                cnt++;
                int mid = (tmp + prev) / 2;
                ans[mid] = 'G';
                tmp = i;
                prev = i;
            }
        }
        if(tmp != -1) {
            ans[(tmp + prev) / 2] = 'G';
            cnt++;
        }

        tmp = -1; prev = -1;
        for(int i = 0; i < n; i++) {
            if(!h[i]) continue;
            if(tmp == -1) {
                tmp = i; prev = i;
                continue;
            }
            if(i <= tmp + 2 * k) {
                prev = i;
            } else {
                int mid = (tmp + prev) / 2;
                cnt++;
                if(ans[mid] == 'G') {
                    if(mid - k >= 0 && mid + k < n && g[mid - k] && g[mid + k]) {
                        ans[mid - 1] = 'H';
                    } else {
                        ans[mid] = 'H';
                        ans[mid-1] = 'G';
                    }
                }
                else ans[mid] = 'H';
                tmp = i;
                prev = i;
            }
        }
        if(tmp != -1) {
            int mid = (tmp + prev) / 2;
            cnt++;
            if(ans[mid] == 'G') {
                if(mid - k >= 0 && mid + k < n && g[mid - k] && g[mid + k]) {
                    ans[mid - 1] = 'H';
                } else {
                    ans[mid] = 'H';
                    ans[mid-1] = 'G';
                }
            }
            else ans[mid] = 'H';
        }

        cout << cnt << '\n';
        for(int i = 0; i < n; i++) {
            if(ans[i]) cout << ans[i];
            else cout << '.';
        }
        cout << '\n';
        memset(g, false, sizeof(g));
        memset(h, false, sizeof(h));
    }
}