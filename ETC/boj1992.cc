#include<stdio.h>
int arr[65][65];
void quad(int lu, int ru, int lb, int rb){
    bool flag = false;
    for(int i = lb; i <= rb; i++){
        if(flag) break;
        for(int j = lu; j <= ru; j++){
            if(arr[i][j] != arr[lb][lu]){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        printf("(");
        int mu = (lu + ru) / 2;
        int mb = (lb + rb) / 2;
        quad(lu, mu, lb, mb);
        quad(mu+1, ru, lb, mb);
        quad(lu, mu, mb+1, rb);
        quad(mu+1, ru, mb+1, rb);
        printf(")");
    }
    else printf("%d", arr[lb][lu]);
}
int main(){
    int n; scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    quad(1, n, 1, n);
}