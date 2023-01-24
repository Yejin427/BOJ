#include<iostream>
using namespace std;
bool apple[101][101];
char pos[101][101];
typedef pair<int, int> p;
int n, cant_go;
p d[4] = { {0,1},{0,-1},{1,0},{-1,0} };
typedef struct {
	p head, tail;
	char direction;
}snake;
void tail_cut(snake* s) {
	if (pos[s->tail.first][s->tail.second] == 'r') {//오른쪽
		pos[s->tail.first][s->tail.second] = 0;//뱀 길이 줄임
		s->tail.second++;
	}
	else if (pos[s->tail.first][s->tail.second] == 'l') {
		pos[s->tail.first][s->tail.second] = 0;
		s->tail.second--;
	}
	else if (pos[s->tail.first][s->tail.second] == 'u') {
		pos[s->tail.first][s->tail.second] = 0;
		s->tail.first--;
	}
	else {
		pos[s->tail.first][s->tail.second] = 0;
		s->tail.first++;
	}
}
bool isok(int x, int y) {
	if (x<1 || x>n || y<1 || y>n || pos[x][y]) {//벽을 벗어나거나 본인몸과 부딪침
		cant_go = 1;
		return false;
	}
	else {
		return true;
	}
}
void snake_move(snake* s) {
	if (s->direction == 'r') {
		if (isok(s->head.first, ++s->head.second)) {
			pos[s->head.first][s->head.second] = 'r';
		}
	}
	else if (s->direction == 'l') {
		if(isok(s->head.first,--s->head.second)) pos[s->head.first][s->head.second] = 'l';
	}
	else if (s->direction == 'u') {
		if (isok(--s->head.first, s->head.second)) pos[s->head.first][s->head.second] = 'u';
	}
	else {
		if (isok(++s->head.first, s->head.second)) pos[s->head.first][s->head.second] = 'd';
	}//머리 길이 증가
	if (!apple[s->head.first][s->head.second]) {//사과 없으면
		tail_cut(s);//꼬리 감소
	}
	else {
		apple[s->head.first][s->head.second] = false;//사과를 없애줌
	}
}
char change_dir(snake* s, char dir) {
	if (dir == 'D') {
		if (s->direction == 'r') return 'd';
		else if (s->direction == 'l') return 'u';
		else if (s->direction == 'u') return 'r';
		else return 'l';
	}
	else {
		if (s->direction == 'r') return 'u';
		else if (s->direction == 'l') return 'd';
		else if (s->direction == 'u') return 'l';
		else return 'r';
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,l; cin >> n >> k;
	snake* s = new snake;
	while (k--) {
		int row, col; cin >> row >> col;
		apple[row][col] = true;
	}
	pos[1][1] = true;
	s->head = { 1,1 }; s->tail = { 1,1 };
	s->direction = 'r';//left,right,up,down
	pos[1][1] = 'r';
	int time = 0;
	cin >> l;
	while (l--) {
		int sec; char dir; cin >> sec >> dir;
		while (sec-time) {
			if (!cant_go) {
				snake_move(s);//움직이고
				time++;//1초지남
			}
			else break;
		}
		s->direction=change_dir(s, dir);
		pos[s->head.first][s->head.second] = s->direction;
	}
	if (!cant_go) {//방향 다 바꾼 뒤에도 이동가능하면
		while (!cant_go) {//이동 불가능할때까지 이동하기
			snake_move(s);
			time++;
		}
	}
	cout << time;
}