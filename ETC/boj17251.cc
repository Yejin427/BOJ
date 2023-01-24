#include<iostream>
using namespace std;
int arr[1000001];
int main(){
    int n; cin >> n;
    int strongest = 0, start = 0, end = 0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(strongest < arr[i]){
            strongest = arr[i];
            start = i; end = i;
        }
        if(strongest == arr[i]){
            end = i;
        }
    }
    if(start-1 > n-end) cout << "B";
    else if(start-1 < n-end) cout << "R";
    else cout << "X";
}