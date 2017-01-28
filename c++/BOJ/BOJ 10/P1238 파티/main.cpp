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

int m[1001][1001];
int N, M, X;

int main() {

	scanf("%d %d %d", &N, &M, &X);

	for (int i = 0; i <= N; i++) {
		fill(m[i], m[i] + N + 1, INF);
	}

	for (int i = 0; i < M; i++) {
		int start, dest, cost;
		scanf("%d %d %d", &start, &dest, &cost);
		m[start][dest] = cost;
		//m[dest][start] = cost;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (m[i][k] + m[k][j] < m[i][j]) {
					m[i][j] = m[i][k] + m[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		ans = max(ans, m[i][X] + m[X][i]);
	}

	printf("%d\n", ans);

	return 0;
}