#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct Point {
	int x1, y1, x2, y2, depth, idx;
};
Point list[5010];
int map[5010][5010];
int depth[5010];
int N, M, K;
vector<int> edges[5010];

int dfs(int n, int d) {
	int &ret = depth[n];
	if (ret != -1) return ret;

	ret = 1;

	int t=1;
	for (int i = 0; i < edges[n].size(); i++) {
		t = max(t, dfs(edges[n][i], d) + 1);
	}
	ret = max(ret, t);
	return ret;
}


int main(int argc, char** argv) {
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	
	int a, b, c, d;
	int x11, y11, x12, y12, x21, y21, x22, y22;
	Point p1, p2;
	bool check;


	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.

		scanf("%d %d %d", &N, &M, &K);


		
		memset(map, 0, sizeof(map));
		memset(depth, -1, sizeof(depth));

		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			Point p;
			p.x1 = a, p.x2 = c, p.y1 = b, p.y2 = c, p.depth=0;
			list[i] = p;
		}

		for (int i = 0; i < K; i++) edges[i].clear();

		
		bool ok = false;
		int ans = 0;
		while (ok == false) {
			ok = true;
			for (int i = 0; i < K; i++) {
				if (list[i].depth < ans) continue;
				for (int j = 0; j < K; j++) {
					if (i == j || list[j].depth < ans) continue;
					if (list[i].x1 <= list[j].x1 && list[j].x2 <= list[i].x2 && list[i].y1 <= list[j].y1 && list[j].y2 <= list[i].y2) {
						list[j].depth = ans + 1;
						ok = false;
					}
				}
			}
			ans++;
		}
		
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}