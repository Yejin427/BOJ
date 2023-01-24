#include<iostream>
using namespace std;
int arr[1003];
int fibo(int n) {
    if (n == 1) arr[n] = 1;
    if (n == 2) arr[n] = 3;
    if (arr[n] > 0) return arr[n];
    arr[n]=(fibo(n - 1) + 2 * fibo(n - 2))%10007;
    return arr[n];
}
int main() {
    int n;
    cin >> n;
    cout << fibo(n);
}