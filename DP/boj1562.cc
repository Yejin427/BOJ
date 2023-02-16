#include<iostream>
#include<algorithm>
#define MOD 1000000000
using namespace std;
long long arr[101][10][1<<10];//자릿수, 끝나는 숫자, 나온 숫자
int statebit(int k, int num){
    int state = k % (1 << num);
    state += (1 << num);
    state += (1 << (num+1)) * (k / (1 << num));
    return state;
}
int main(){
    int n; cin >> n;
    for(int i=1;i<10;i++){
        arr[1][i][(1<<i)] = 1;
    }
    for(int i = 2; i <= n; i++){//100
        for(int j = 0; j < 10; j++){//10
            for(int k = 0; k < 512; k++){
                if(j > 0){
                    int sb = statebit(k, j-1);
                    arr[i][j][(sb | (1 << j))] += arr[i-1][j-1][sb];
                    arr[i][j][(sb | (1 << j))] %= MOD;
                }
                if(j < 9){
                    int sb = statebit(k, j+1);
                    arr[i][j][(sb | (1 << j))] += arr[i-1][j+1][sb];
                    arr[i][j][(sb | (1 << j))] %= MOD;
                }
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<10;i++){
        ans += arr[n][i][1023];
    }
    cout << ans % MOD;
}