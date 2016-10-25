#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <deque>
#include <functional>
using namespace std;

// ������ ll �̻��� ��� INF�� 98765432100000 �������� ũ�� �ؾ���
// �Է¹޴� ���� 10^9 �̰� ���� ���� �װ͵��� ���ϴ� �����̶�� ���� ll �ϼ� �ִ�
// priority_queue �� �⺻������ �������� �����̴�. ������������ �ϰ� �ʹٸ� priority_queue<int, vector<int>, greater<int>>
// queue���� pop�ϱ� ������ �ݵ�� empty�� ��츦 üũ�ϰ� ����ó�� �����


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

pair<int, int> point[100010];
pair<int, int> hole[100010];
int N,K;
int sum;
int visit[100010];

int calLeft(int sx, int sy, int dx, int dy, int cur) {
	if (point[cur].second == 0) {
		return abs(sx - point[cur].first)*sy;
	}

	visit[cur] = 1;

	if (point[cur].first == dx && point[cur].second == dy) {
		return abs(sx - dx)*abs(sy);
	}


	if (visit[cur - 1] == 1) {
		return abs(sx - point[cur].first)*abs(sy);
	}


	if (sy <= point[cur].second) return calLeft(sx, sy, dx, dy, cur - 1);
	else {
		return calLeft(point[cur].first, point[cur].second, dx, dy, cur - 1) + (abs(point[cur].first - sx)*sy);
	}
}

int calRight(int sx, int sy, int dx, int dy, int cur) {
	if (point[cur].second == 0) {
		return abs(sx - point[cur].first)*sy;
	}

	visit[cur] = 1;

	if (point[cur].first == dx && point[cur].second == dy) {
		return abs(sx-dx)*abs(sy);
	}

	if (visit[cur + 1] == 1) {
		return abs(sx - point[cur].first)*abs(sy);
	}

	if (sy <= point[cur].second) return calRight(sx, sy, dx, dy, cur + 1);
	else {
		return calRight(point[cur].first, point[cur].second, dx, dy, cur + 1) + (abs(point[cur].first - sx)*sy);
	}
}

int main() {

	scanf("%d", &N);

	int x1, y1, x2, y2;
	scanf("%d %d", &x1, &y1);
	point[0] = mp(x1, y1);
	for (int i = 1; i < N-1; i+=2) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		point[i] = mp(x1, y1);
		point[i+1] = mp(x2, y2);
		sum += (x2 - x1)*y1;
	}
	scanf("%d %d", &x1, &y1);
	point[N-1] = mp(x1, y1);

	scanf("%d", &K);
	int hole_cnt = 0;
	hole[hole_cnt++] = mp(0, 0);
	for (int j = 0; j < K; j++) {
		for (int k = 0; k < 2; k++) {
			scanf("%d %d", &x1, &y1);
			hole[hole_cnt++] = mp(x1, y1);
		}
	}
	hole[hole_cnt++] = mp(point[N - 1].first, point[N - 1].second);

	for (int i = 1; i < hole_cnt-2; i+=2) {
		int cur = 0;
		for (int j = 0; j < N; j++) {
			if (point[j].first == hole[i].first && point[j].second == hole[i].second) {
				cur = j;
				break;
			}
		}
		sum -= calLeft(hole[i].first, hole[i].second, hole[i - 1].first, hole[i - 1].second, cur);
		sum -= calRight(hole[i+1].first, hole[i+1].second, hole[i + 2].first, hole[i + 2].second, cur+1);
		sum -= (hole[i + 1].first - hole[i].first)*hole[i].second;
	}

	printf("%d\n", sum);


	return 0;
}