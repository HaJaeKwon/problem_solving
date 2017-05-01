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

#define MAX 100000

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {

		int N;
		
		vector<int> prev(MAX, INF);
		int a, b;
		scanf("%d", &N);
		scanf("%d %d", &a, &b);
		prev[a] = 0;
		prev[0] = b;

		for (int i = 1; i < N; i++) {
			scanf("%d %d", &a, &b);

			vector<int> DP(MAX, INF);

			for (int i = MAX - 1; i >= 0; i--) {
				if (prev[i] != INF) {
					DP[i] = min(DP[i], prev[i] + b);
				}
			}

			for (int i = MAX - 1; i >= 0; i--) {
				if (prev[i] != INF) {
					DP[i + a] = min(DP[i + a], prev[i]);
				}
			}

			for (int i = MAX - 1; i >= 0; i--) {
				prev[i] = DP[i];
			}
		}

		int ans = INF;
		for (int i = MAX - 1; i >= 0; i--) {
			ans = min(ans, max(prev[i], i));
		}
		printf("%d\n", ans);
	}

	return 0;
}