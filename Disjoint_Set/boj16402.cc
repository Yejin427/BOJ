#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string, int> kname;
vector<string> king;
vector<string> answer;
int parent[501];
int find(int x){
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void merge(int x, int y){   //x승리 y패배
    int rx = find(x);
    int ry = find(y);
    parent[ry] = rx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cin.ignore();
    
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=1;i<=n;i++){
        string kingdom, of, name;
        cin >> kingdom >> of >> name;
        kname[name] = i;
        king.push_back(name);
    }
    
    for(int i=1;i<=m;i++){
        string kingdom, of, name1, name2, num;
        cin >> kingdom >> of >> name1 >> of >> name2;
        string rname1 = name1.substr(0, name1.size()-8);
        string rname2 = name2.substr(0, name2.size()-2);
        char win = name2.back();
        // cout << rname1 << ' '<<rname2<<' '<<win<<'\n';
        
        int knum1 = kname[rname1];
        int knum2 = kname[rname2];
        // cout << "Knum: "<<knum1<<" "<<knum2<<"\n";
        if(find(knum1) != find(knum2)){
            if(win == '1'){
                merge(knum1, knum2);
            }
            else{
                merge(knum2, knum1);
            }
        }
        else{   //속국 왕국 싸움
            if(find(knum1) == knum1 && win == '2'){   //2가 속국
                parent[knum2] = knum2;
                parent[knum1] = knum2;
            }
            else if(find(knum2) == knum2 && win == '1'){   //1가 속국
                parent[knum1] = knum1;
                parent[knum2] = knum1;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i){
            ans++;
            answer.push_back(king[i-1]);
        }
    }
    cout << ans<<'\n';

    sort(answer.begin(), answer.end());
    for(auto& a: answer){
        cout << "Kingdom of "<<a<<'\n';
    }
}