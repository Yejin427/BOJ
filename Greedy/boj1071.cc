#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main() {
    int n; cin >> n;
    v.resize(n);
    // int maxnum = 0, minnum = 1001;
    for(int i=0;i<n;i++){
        cin >> v[i];

    }
    sort(v.begin(), v.end());

    vector<int> ans;
    int idx = 0;
    while(idx < n-1) {
        // cout << "idx: "<<idx<<'\n';
        if(v[idx+1] == v[idx] + 1) {
            int nxt = idx+2;
            while(nxt < n && v[nxt] == v[idx+1]) nxt++;
            if(nxt >= n) {  //뒤에꺼를 끼울수 없음 -> 앞에 끼움
                int startp = idx;
                while(v[startp] == v[idx]) startp--;
                startp++;
                int endp = n-1;
                while(startp < endp && v[startp] != v[endp]) {
                    int tmp = v[startp];
                    v[startp] = v[endp];
                    v[endp] = tmp;
                    startp++; endp--;
                }
                break;
            }
            else {
                int tmp = v[idx + 1];   //그 다음과 swap
                v[idx+1] = v[nxt];
                v[nxt] = tmp;
                idx = nxt;
            }
        }
        else {
            idx++;
        }
    }
    
    for(int i: v) cout << i << ' ';
}