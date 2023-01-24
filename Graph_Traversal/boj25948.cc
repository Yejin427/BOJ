#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> visited;   //경로 확정
vector<bool> indeg;
vector<int> edge;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n; cin >> m >> n;
    for(int i=0;i<n;i++) {
        edge.push_back(-1);
        indeg.push_back(false);
        visited.push_back(-1);
    }
    for(int i=1;i<=m;i++){
        int a,b; cin >> a >> b;
        indeg[b] = true;
        edge[a] = b;
    }
    int maxans = 0;
    for(int i=0;i<n;i++){
        if(!indeg[i]){
            int curedge = i;
            stack<int> s;
            while(curedge != -1 && visited[curedge] == -1){
                s.push(curedge);
                visited[curedge] = 0;
                curedge = edge[curedge];
            }
            if(curedge == -1){  //더 갈 곳 없어 마무리
                int num = 0;
                while(!s.empty()){
                    visited[s.top()] = (++num);
                    s.pop();
                }
                maxans = max(num, maxans);
            }
            else if(visited[curedge] != 0){   //이미 지난 곳 만남
                int num = visited[curedge];
                while(!s.empty()){
                    visited[s.top()] = (++num);
                    s.pop();
                }
                maxans = max(num, maxans);
            }
            else{   //visited[curedge] == 0;
                vector<int> v;
                while(s.top() != curedge){
                    v.push_back(s.top());
                    s.pop();
                }
                v.push_back(s.top()); s.pop();
                for(auto& node: v) visited[node] = v.size();
                int num = v.size();
                while(!s.empty()){
                    visited[s.top()] = (++num);
                    s.pop();
                }
                maxans = max(num, maxans);
            }
        }
    }
    //cycle 처리
    for(int i=0;i<n;i++){
        if(visited[i] == -1){
            int cycle = 0;
            int curedge = i;
            while(curedge != -1 && visited[curedge] == -1){
                visited[curedge] = 1;
                cycle++;
                curedge = edge[curedge];
            }
            maxans = max(cycle, maxans);
        }
    }
    //for(int i=0;i<n;i++) cout <<"visited i: "<<visited[i]<<'\n';

    cout << maxans;
}