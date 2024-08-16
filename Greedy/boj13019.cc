// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;

// char a[100001];
// int parent[100001];
// struct Mit{
//     int dad = 0;
//     int mom = 0;
//     char gen;
//     bool alive = true;
// };
// vector<Mit> dna;
// int findParent(int id) {
//     int cur = id;
//     while(dna[cur].mom != 0) {
//         cur = dna[cur].mom;
//     }
//     return cur;
// }
// int main(){
//     int n; cin >> n;
//     struct Mit mit;
//     dna.push_back(mit);
//     for(int i=1;i<=n;i++) {
//         char gen; cin >> gen;
//         struct Mit mit;
//         mit.gen = gen;
//         dna.push_back(mit);
//     }
//     int m; cin >> m;
//     for(int i=1;i<=m;i++) {
//         int dad,mom; char gen;
//         cin >> dad;
//         if(dad > 0) {
//             cin >> mom >> gen;
//             struct Mit mit;
//             mit.dad = dad;
//             mit.mom = mom;
//             mit.gen = gen;
//             dna.push_back(mit);
//         } else {
//             dna[-dad].alive = false;
//         }
//     }
//     int k; cin >> k;
//     while(k--) {
//         int id, num; cin >> id >> num;
//         int m_id = findParent(id);
        
//     }
//     vector<int> mother;
//     for(int i=1;i<=n;i++) {
//         if(dna[i].alive) {
//             if(dna[i].mom != 0) {
//                 mother.push_back(dna[i].mom);
//             } else {
//                 mother.push_back(i);
//             }
//         }
//     }
    
// }
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    
    int idx = b.length()-1;
    int ans = 0;
    for(int i=a.length()-1;i>=0;i--) {
        if(a[i] == b[idx]) idx--;
        else ans++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a == b) cout << ans;
    else cout << -1;
}