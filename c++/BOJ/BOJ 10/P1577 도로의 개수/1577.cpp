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

int N, M, K;
ll DP[101][101];
tuple<int, int, int, int> load[101];

int main() {

	scanf("%d %d", &N, &M);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		load[i] = mt(min(b, d), min(a, c), max(b, d), max(a, c));
	}
	DP[0][0] = 1;
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			bool left = true;
			bool down = true;
			if (j == 0) left = false;
			if (i == 0) down = false;
			for (int k = 0; k < K; k++) {
				int a, b, c, d;
				tie(a, b, c, d) = load[k];
				if (c == i && d == j && a == i && b == j - 1) left = false;
				if (c == i && d == j && a == i - 1 && b == j) down = false;
			}
			if (left) {
				DP[i][j] += DP[i][j - 1];
			}
			if (down) {
				DP[i][j] += DP[i - 1][j];
			}
		}
	}

	printf("%lld\n", DP[M][N]);

	return 0;
}