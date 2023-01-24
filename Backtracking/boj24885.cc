#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[11];
int n,m,k;
ll ans;
void backtracking(int day, ll money, int num, ll borrow){
    if(day == n){
        money += arr[day] * num;
        ans = max(ans, money);
        return;
    }
    backtracking(day+1, money, num, borrow);    //매도 매수 x

    ll nmoney = money;
    ll nborrow = borrow;  //빌리기
    if(nborrow != 0){//갚기
        ll pay = min(nmoney, nborrow);
        nborrow -= pay;
        nmoney -= pay;
    }
    if(nborrow == 0){   //전액 상환함
        nborrow = k * nmoney;
        nmoney += nborrow;
        if(nmoney / arr[day] != 0){  //하나도 못사면 빌릴 수 없음
            ll nnum = num + (nmoney / arr[day]);
            nmoney %= arr[day];
            backtracking(day+1, nmoney, nnum, nborrow);    //매도x, 매수o
        }
    }
    nmoney = money;
    nmoney += arr[day] * num;
    backtracking(day+1, nmoney, 0, borrow);   //매도o, 매수x

    nmoney = money;
    nborrow = borrow;
    nmoney += arr[day] * num;   //매도
    if(nborrow != 0){
        ll pay = min(nmoney, nborrow);
        nborrow -= pay;
        nmoney -= pay;
    }
    if(nborrow == 0){   //전액 상환함 -> 빌리고 매수 가능
        nborrow = k * nmoney;
        nmoney += nborrow;
        if(nmoney / arr[day] != 0){  //하나도 못사면 빌릴 수 없음
            ll nnum = nmoney / arr[day];
            nmoney %= arr[day];
            backtracking(day+1, nmoney, nnum, nborrow);    //매도o, 매수o
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    backtracking(1, m, 0, 0);
    cout << ans;
}