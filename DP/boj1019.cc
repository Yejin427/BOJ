#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long cnt[10];
long long hundred[100][10]; //100단위로 쪼개서 계산
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n; cin >> n;

    for(int i=1;i<100;i++) {
        int num = i;
        for(int j=0;j<=9;j++) hundred[i][j] = hundred[i-1][j];
        while(num != 0) {
            hundred[i][num % 10]++;
            num /= 10;
        }
    }
    if(n < 100) {
        for(int i=0;i<=9;i++) cout << hundred[n][i] << ' ';
    }
    else {
        for(int i=0;i<=9;i++) hundred[i][0] = i + 2;
        for(int i=10;i<=99;i++) hundred[i][0] += 11;

        long long tmp = n;
        long long times = 1;
        while(tmp != 0) {
            // for(int i=0;i<=9;i++) cout << cnt[i] << ' ';
            // cout << '\n';
            // cout << "tmp: "<<tmp<<'\n';
            long long q = tmp / 100;
            long long r = tmp % 100;
            // cout << "q: "<<q<<" r: "<<r<<" times: "<<times<<'\n';
            if(q == 0) {
                for(int i=1;i<=r-1;i++) {
                    int qq = i / 10;
                    int rr = i % 10;
                    if(qq != 0) {
                        cnt[qq] += times;
                    }
                    cnt[rr] += times;
                }
                int qq = r / 10, rr = r % 10;
                if(qq != 0) cnt[qq] += n % times + 1;
                cnt[rr] += n % times + 1;
                break;
            }
            for(int i=0;i<=9;i++) {
                cnt[i] += (hundred[99][i] - hundred[9][i]) * times;
                if(i !=0) cnt[i]+=times;
            }
            for(int i=0;i<=9;i++) {
                cnt[i] += hundred[99][i] * (q-1) * times;
            }
            if(r) {
                for(int i=0;i<=9;i++) {
                    cnt[i] += hundred[r-1][i] * times;
                }
            }
            int qq = r / 10, rr = r % 10;
            cnt[qq] += n % times + 1;
            cnt[rr] += n % times + 1;

            tmp /= 100;
            times *= 100;
        }
        for(int i=0;i<=9;i++) cout << cnt[i] <<' ';
    }
}