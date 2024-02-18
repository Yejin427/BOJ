#include<iostream>
#include<algorithm>
using namespace std;
int arr[700];
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    sort(arr+1, arr+n+1);
    int ans = 2e9;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int head = 1, body = n; //여기서 만드는 눈사람이 더 큼
            int smallheight = arr[i] + arr[j];
            //cout << "smallheight: "<<smallheight<<'\n';
            int tmp = 2e9;
            while(head < body){
                if(head == i || head == j){
                    head++;
                    continue;
                }
                if(body == i || body == j) {
                    body--;
                    continue;
                }
                if(arr[head] + arr[body] >= smallheight){
                    tmp = min(arr[head] + arr[body] - smallheight, tmp);
                    //cout << "tmp: "<<tmp<<'\n';
                    body--;
                }
                else{
                    head++;
                }
            }
            ans = min(tmp, ans);
        }
    }
    cout << ans;
}