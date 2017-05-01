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
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	
	int a, b, c, d;
	int x11, y11, x12, y12, x21, y21, x22, y22;
	Point p1, p2;
	bool check;


	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

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
		
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}