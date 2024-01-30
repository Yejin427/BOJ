#include<iostream>
#include<algorithm>
using namespace std;
int arr[300001];
int main() {
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++) {
        if(i % 2 != arr[i] % 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}