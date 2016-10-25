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

int N, M, K;

int main() {

	scanf("%d %d %d", &N, &M, &K);

	vector<int> v[1000];

	if (M + K - 1 <= N && N <= M*K) {

		int current = 1;
		for (; current <= K; current++) {
			v[0].push_back(current);
		}
		reverse(v[0].begin(), v[0].end());

		int bound = (N - K) / (M - 1);
		for (int i = 1; i < M; i++) {
			for (int j = 0; j < bound; j++, current++) {
				v[i].push_back(current);
			}
			reverse(v[i].begin(), v[i].end());
		}

		for (int i = 0; i < M; i++) {
			for (int j : v[i]) {
				printf("%d ", j);
			}
		}
	}
	else {
		printf("-1\n");
	}


	return 0;
}