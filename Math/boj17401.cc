#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define MOD 1000000007
using namespace std;

long long road[101][21][21];   //주기, a, b -> 경로 개수
int n;
vector<vector<long long>> I(21, vector<long long>(21, 0));
vector<vector<long long>> multiply(vector<vector<long long>> A, vector<vector<long long>> B) {
    vector<vector<long long>> matrix(n+1, vector<long long>(n+1, 0));

    for(int s=1;s<=n;s++) {
        for(int e=1;e<=n;e++) {
            //s -> e 
            for(int k=1;k<=n;k++) {
                matrix[s][e] += A[s][k] * B[k][e];
                matrix[s][e] %= MOD;
            }
        }
    }
    return matrix;
}
vector<vector<long long>> multiply2(vector<vector<long long>> A, int idx) {
    vector<vector<long long>> matrix(n+1, vector<long long>(n+1, 0));

    for(int s=1;s<=n;s++) {
        for(int e=1;e<=n;e++) {
            //s -> e 
            for(int k=1;k<=n;k++) {
                matrix[s][e] += A[s][k] * road[idx][k][e];
                matrix[s][e] %= MOD;
            }
        }
    }
    return matrix;
}

vector<vector<long long>> power(vector<vector<long long>> A, int num){
    if(num == 0) return I;
    else if(num == 1) return A;
    else {
        vector<vector<long long>> half = power(A, num/2);
        if(num % 2 != 0) {
            return multiply(multiply(half, half), A);
        } else {
            return multiply(half, half);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,d; 
    cin >> t >> n >> d;
    for(int i=1;i<=t;i++) {
        int mi; cin >> mi;
        while(mi--) {
            int a,b; long long c; 
            cin >> a >> b >> c;
            road[i][a][b] = c;
        }
    }

    //한주기동안 각 지점 -> 지점 도달 경우의수
    vector<vector<long long>> ans(n+1, vector<long long>(n+1, 0));
    for(int i=1;i<=n;i++) {
        I[i][i] = 1;
        ans[i][i] = 1;
    }

    for(int i=1;i<=t;i++) {
        ans = multiply2(ans, i);
    }

    int cycleCnt = d / t; int rest = d % t;

    ans = power(ans, cycleCnt);
    
    for(int i=1;i<=rest;i++) {
        ans = multiply2(ans, i);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}