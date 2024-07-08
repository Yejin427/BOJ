#include<iostream>
#include<algorithm>
using namespace std;
int ans, arr[10];
int map[33] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 
                20, 13, 16, 19, 25, 22, 24, 26, 28, 30, 
                32, 34, 36, 38, 40, 28, 27, 26, 22, 24, 30, 35, 0};
int nxt(int idx) {
    switch(idx) {
        case 10: 
            return 15;
        case 14: 
            return 30;
        case 27:
            return 14;
        case 29:
            return 14;
        case 31:
            return 24;
        case 24:
            return 32;
        default:
            return idx+1;
    }
}
int move(int pos, int amount) {
    int move = pos;
    if(pos == 5) {
        move = 11;
        for(int i=1;i<amount;i++) {
            if(move == 32) break;
            move = nxt(move);
        }
    }
    else if(pos == 10) {
        move = 28;
        for(int i=1;i<amount;i++) {
            if(move == 32) break;
            move = nxt(move);
        }
    }
    else if(pos == 19) {
        move = 25;
        for(int i=1;i<amount;i++) {
            if(move == 32) break;
            move = nxt(move);
        }
    }
    else {
        for(int i=1;i<=amount;i++) {
            if(move == 32) break;
            move = nxt(move);
        }
    }
    return move;
}
void dfs(int idx, int score, int p1, int p2, int p3, int p4) {
    if(idx == 10) {
        // cout << "score: "<<score<<'\n';
        ans = max(ans, score);
        return;
    }
    int p1move = move(p1, arr[idx]);
    // cout << "p1move: "<<p1move<<'\n';
    if(p1 != 32 && (p1move == 32 || (p1move != p2 && p1move != p3 && p1move != p4))) {
        dfs(idx+1, score + map[p1move], p1move, p2, p3, p4);
    }
    int p2move = move(p2, arr[idx]);
    // cout << "p2move: "<<p2move<<'\n';
    if(p2 != 32 && (p2move == 32 || (p2move != p1 && p2move != p3 && p2move != p4))) {
        dfs(idx+1, score + map[p2move], p1, p2move, p3, p4);
    }
    int p3move = move(p3, arr[idx]);
    // cout << "p3move: "<<p3move<<'\n';
    if(p3 != 32 && (p3move == 32 || (p3move != p1 && p3move != p2 && p3move != p4))) {
        dfs(idx+1, score + map[p3move], p1, p2, p3move, p4);
    }
    int p4move = move(p4, arr[idx]);
    // cout << "p4move: "<<p4move<<'\n';
    if(p4 != 32 && (p4move == 32 || (p4move != p1 && p4move != p2 && p4move != p3))) {
        dfs(idx+1, score + map[p4move], p1, p2, p3, p4move);
    }

}
int main() {
    for(int i=0;i<10;i++) cin >> arr[i];
    dfs(0, 0, 0, 0, 0, 0);
    cout << ans;
}