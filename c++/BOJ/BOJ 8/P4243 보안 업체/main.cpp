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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

ll DP[110][110][3];
ll dis[110];
int N;

ll f(int left, int right, int pos, int cnt) {
	if (left == 1 && right == N) return 0;
	if (left<1 || right > N) return INF;

	ll &ret = DP[left][right][pos];
	if (ret != -1) return ret;

	ret = INF;

	ll cost;
	if (pos == 0) {
		if (right < N) {
			cost = dis[right + 1] - dis[left];
			ret = min(ret, cost*cnt + f(left, right + 1, 1, cnt - 1));
		}
		if (left > 1) {
			cost = dis[left] - dis[left - 1];
			ret = min(ret, cost*cnt + f(left - 1, right, 0, cnt - 1));
		}
	}
	else {
		if (right < N) {
			cost = dis[right + 1] - dis[right];
			ret = min(ret, cost*cnt + f(left, right + 1, 1, cnt - 1));
		}
		if (left > 1) {
			cost = dis[right] - dis[left - 1];
			ret = min(ret, cost*cnt + f(left - 1, right, 0, cnt - 1));
		}
	}

	return ret;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {

		int a, b;
		memset(DP, -1, sizeof(DP));
		memset(dis, 0, sizeof(dis));

		scanf("%d", &N);
		scanf("%d", &a);
		scanf("%lld", &dis[2]);
		for (int i = 3; i <= N; i++) {
			scanf("%d", &b);
			dis[i] = dis[i - 1] + b;
		}
		dis[N + 1] = dis[N];
		printf("%lld\n", f(a, a, 0, N - 1));

	}

	return 0;
}