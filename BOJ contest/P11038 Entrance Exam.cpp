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
int N, nmin, nmax;
int P[201];
int main() {

	while (1) {
		scanf("%d%d%d", &N, &nmin, &nmax);
		if (N == 0 && nmin == 0 && nmax == 0) break;

		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}

		int gap = 0;
		int ans = 1;
		for (int i = 1; i<nmin; i++) {
			ans++;
			//gap = max(gap, P[i-1] - P[i]);
		}
		gap = P[nmin - 1] - P[nmin];
		for (int i = nmin; i<nmax; i++) {
			if (gap <= P[i] - P[i+1]) {
				ans = i + 1;
				gap = P[i] - P[i+1];
			}
		}
		printf("%d\n", ans);
	}


	return 0;
}