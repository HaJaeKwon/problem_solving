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
#include <sstream>
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

int n, a, b;

int f(int cur, vector<int> &DP, vector<pair<int,int>> &v) {
	if (cur > n) return 0;

	int &ret = DP[cur];
	if (ret != -1) return ret;

	int cost;
	ret = INF;

	cost = v[cur].first - v[cur-1].first + (v[cur].second-v[cur-1].second) * 2;
	ret = min(ret, cost + f(cur + 1, DP, v));

	cost = 3 + (v[cur].second - v[cur - 1].second) * 2;
	ret = min(ret, cost + f(cur + 1, DP, v));

	cost = 6;
	ret = min(ret, cost + f(cur + 1, DP, v));

	cost = 18 + (v[cur + 6].second - v[cur - 1].second) * 2;
	ret = min(ret, cost + f(cur + 7, DP, v));

	if (v[cur + 6].second == v[cur+1].second) {
		cost = 24;
		ret = min(ret, cost + f(cur + 7, DP, v));
	}

	cost = 36;
	ret = min(ret, cost + f(cur + 7, DP, v));

	cost = 45 + (v[cur + 29].second - v[cur - 1].second) * 2;
	ret = min(ret, cost + f(cur + 30, DP, v));

	if (v[cur + 29].second == v[cur + 1].second) {
		cost = 51;
		ret = min(ret, cost + f(cur + 30, DP, v));
	}

	if (v[cur + 29].second == v[cur + 7].second) {
		cost = 81;
		ret = min(ret, cost + f(cur + 30, DP, v));
	}

	cost = 90;
	ret = min(ret, cost + f(cur + 30, DP, v));

	return ret;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);

		vector<pair<int, int>> v(n + 35, mp(0, 0));
		vector<int> DP(n + 1, -1);

		scanf("%d %d", &v[1].first, &v[1].second);
		for (int i = 2; i <= n; i++) {
			scanf("%d %d", &a, &b);
			v[i].first = v[i - 1].first + a;
			v[i].second = v[i - 1].second + b;
		}
		for (int i = n+1; i <= n+31; i++) {
			v[i].first = v[i - 1].first;
			v[i].second = v[i - 1].second;
		}

		printf("%d\n", f(1, DP, v));

	}

	return 0;
}