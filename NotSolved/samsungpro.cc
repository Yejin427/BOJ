#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <time.h>
using namespace std;
extern void init(int N, int mId[], int mNum[]);
extern int add(int mId, int mNum, int mParent);
extern int remove(int mId);
extern int distribute(int K);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_DISTRIBUTE 4

static bool run() {
	int q;
	scanf("%d", &q);

	static int midArr[1000], mnumArr[1000];
	int mid, mnum, mparent, n, k;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d", &midArr[j], &mnumArr[j]);
				}
				init(n, midArr, mnumArr);
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %d %d", &mid, &mnum, &mparent, &ans);
				ret = add(mid, mnum, mparent);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &mid, &ans);
				ret = remove(mid);
				if (ans != ret)
					okay = false;
				break;
			case CMD_DISTRIBUTE:
				scanf("%d %d", &k, &ans);
				ret = distribute(k);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
    clock_t start, finish;
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);
    start = clock();
	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}
    finish = clock();
    printf("%f초", (double)(finish-start)/CLOCKS_PER_SEC);
	return 0;
}
struct Department {
    int num;
    int total;
    int parent;
    vector<int> children;
};

unordered_map<int, Department> departments;
vector<int> roots;

void updateTotal(int id, int diff) {
    while (id != -1) {
        Department& dept = departments[id];
        dept.total += diff;
        id = dept.parent;
    }
}

void init(int N, int mId[], int mNum[]) {
    departments.clear();
    roots.clear();
    for (int i = 0; i < N; ++i) {
        departments[mId[i]] = {mNum[i], mNum[i], -1, {}};
        roots.push_back(mId[i]);
    }
}

int add(int mId, int mNum, int mParent) {
    Department& dept = departments[mParent];
    if (dept.children.size() >= 3) return -1;
    departments[mId] = {mNum, mNum, mParent, {}};
    dept.children.push_back(mId);
    updateTotal(mParent, mNum);
    return dept.total;
}

int remove(int mId) {
    if (!departments.count(mId)) return -1;
    Department& dept = departments[mId];
    int totalRemoved = dept.total;
    int parent = dept.parent;
    if (parent != -1) {
        auto &siblings = departments[parent].children;
        siblings.erase(remove(siblings.begin(), siblings.end(), mId), siblings.end());
    }
    updateTotal(parent, -totalRemoved);
    vector<int> stack = {mId};
    while (!stack.empty()) {
        int cur = stack.back(); stack.pop_back();
        for (int child : departments[cur].children) stack.push_back(child);
        departments.erase(cur);
    }
    return totalRemoved;
}

bool isValid(int L, int K, int &maxGiven) {
    int used = 0;
    maxGiven = 0;
    for (int root : roots) {
        int given = min(departments[root].total, L);
        used += given;
        maxGiven = max(maxGiven, given);
        if (used > K) return false;
    }
    return used <= K;
}

int distribute(int K) {
    int total = 0, maxGroup = 0;
    for (int root : roots) {
        Department& dept = departments[root];
        total += dept.total;
        maxGroup = max(maxGroup, dept.total);
    }
    if (total <= K) return maxGroup;
    
    int lo = 0, hi = maxGroup, best = 0, maxGiven;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (isValid(mid, K, maxGiven)) {
            best = maxGiven;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return best;
}
