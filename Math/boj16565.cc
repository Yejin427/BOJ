#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
ll dp[14][55]; //13개 카드, n장 추출
ll C[55][55];
ll comb(int x, int y) {
    if(x == y || y == 0) return 1;

    if(C[x][y] > 0) return C[x][y];
    return C[x][y] = comb(x-1, y) + comb(x-1, y-1);
}
ll f(int num, int card) {  //포카드를 포함하지 않는 경우
    if(num * 3 < card) return 0;
    if(card < 4) return comb(4 * num, card);
    if(dp[num][card] > 0) return dp[num][card];
    return dp[num][card] = (f(num-1, card) + f(num-1, card-1) * 4 + f(num-1, card-2) * 6 + f(num-1, card-3) * 4);
}
int main() {
    int n; cin >> n;

    // cout << comb(52, n) << '\n';
    // cout << f(13, n);
    cout << (comb(52, n) - f(13, n)) % 10007;
}