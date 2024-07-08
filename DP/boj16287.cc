#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[5001], sum1[500000], sum2[500000];
int main() {
    int w, n; cin >> w >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int half = arr[i] + arr[j];

            if(sum1[half] == 0) {
                sum1[half] = i;
                sum2[half] = j;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int half = w - (arr[i] + arr[j]);
            if(half > 400000 || half < 0 || sum1[half] == 0) continue;
            if(sum1[half] != i && sum2[half] != j && sum1[half] != j && sum2[half] != i) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout <<"NO";
}