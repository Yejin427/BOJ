#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//나라 이름
string name[4];
// 이김 = 0, 비김 = 1, 짐 = 2, 없음 = -1
int results[6] = {-1, };

//경기별로 승, 무승부, 패 확률
double prob[6][3] = {.0};

// <i, i번째 나라 점수>값을 가지는 쌍, 4.5에서 점수를 정렬할 때 사용
pair<int,int> pts[4];

// 각 나라별로 본선에 진출할 확률
double total_probs[4] = {.0};
int pack(pair<int,int> p) {
    if(p.first == 0 && p.second == 1) return 0;
    else if(p.first == 0 && p.second == 2) return 1;
    else if(p.first == 0 && p.second == 3) return 2;
    else if(p.first == 1 && p.second == 2) return 3;
    else if(p.first == 1 && p.second == 3) return 4;
    else if(p.first == 2 && p.second == 3) return 5;
    return -1;
}
pair<int,int> unpack(int idx) {
    switch(idx) {
        case 0: return {0, 1};
        case 1: return {0, 2};
        case 2: return {0, 3};
        case 3: return {1, 2};
        case 4: return {1, 3};
        case 5: return {2, 3};
        default: return {-1, -1};
    }
}

int find(string team) {
    for(int i=0;i<4;i++) {
        if(name[i] == team) return i;
    }
    return -1;
}
void clear_points() {
    for(int i=0;i<4;i++) {
        pts[i].first = i;
        pts[i].second = 0;
    }
}
bool pair_comp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;
}
void set_points() {
    pair<int,int> cons;
    for(int i=0;i<6;i++) {
        cons = unpack(i);
        if(results[i] == 0) {   //win
            pts[cons.first].second += 3;
        }
        else if(results[i] == 1) {
            pts[cons.first].second += 1;
            pts[cons.second].second += 1;
        }
        else {
            pts[cons.second].second += 3;
        }
    }
    sort(pts, pts+4, pair_comp);
}
void dfs(double p, int depth) {
    if(depth != 6) {
        if(prob[depth][0] != 0.0) {
            results[depth] = 0;
            dfs(p * prob[depth][0], depth+1);
        }
        if(prob[depth][1] != 0.0) {
            results[depth] = 1;
            dfs(p * prob[depth][1], depth+1);
        }
        if(p != 0.0) {
            results[depth] = 2;
            dfs(p * prob[depth][2], depth+1);
        }
        return;
    }
    else {
        if(p == 0.0) return;

        clear_points();
        set_points();
        if(pts[0].second == pts[1].second && pts[1].second == pts[2].second
            && pts[2].second == pts[3].second) {
            for(int i=0;i<4;i++) {
                total_probs[i] += p / 2;
            }
        }
        else if(pts[0].second == pts[1].second && pts[1].second == pts[2].second) {
            total_probs[pts[0].first] += 2 * p / 3;
            total_probs[pts[1].first] += 2 * p / 3;
            total_probs[pts[2].first] += 2 * p / 3;
        }
        else if(pts[1].second == pts[2].second && pts[2].second == pts[3].second) {
            total_probs[pts[0].first] += p;
            total_probs[pts[1].first] += p/3;
            total_probs[pts[2].first] += p/3;
            total_probs[pts[3].first] += p/3;
        }
        else if(pts[1].second == pts[2].second){
            total_probs[pts[0].first] += p;
            total_probs[pts[1].first] += p / 2;
            total_probs[pts[2].first] += p / 2;
        }
        else{
            total_probs[pts[0].first] += p;
            total_probs[pts[1].first] += p;
        }

        return;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> name[0] >> name[1] >> name[2] >> name[3];

    for(int i=0;i<6;i++) {
        string t1, t2;
        double win, tie, lose;  
        bool reverse = false;
        cin >> t1 >> t2 >> win >> tie >> lose;

        int idx1 = find(t1);
        int idx2 = find(t2);
        if(idx2 < idx1) {
            int tmp = idx2;
            idx2 = idx1;
            idx1 = tmp;
            reverse = true;
        }
        int packidx = pack({idx1, idx2});
        if(reverse) {
            prob[packidx][0] = lose;
            prob[packidx][1] = tie;
            prob[packidx][2] = win;
        } else {
            prob[packidx][0] = win;
            prob[packidx][1] = tie;
            prob[packidx][2] = lose;
        }
    }
    dfs(1.0, 0);
    
    cout << fixed;
    cout.precision(9);
    cout << total_probs[0] << '\n' << total_probs[1] << '\n' << total_probs[2] << '\n' << total_probs[3];
}