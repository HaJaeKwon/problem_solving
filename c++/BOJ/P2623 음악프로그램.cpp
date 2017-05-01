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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int N, M;
int cnt[1001];
vector<int> v[1001];

vector<int> ans;

void TP() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		ans.push_back(cur);

		for (int i : v[cur]) {
			cnt[i]--;
			if (cnt[i] == 0) {
				q.push(i);
			}
		}

	}

}

int main() {

	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, prev = 0;
		scanf("%d", &a);
		for (int i = 0; i < a; i++) {
			scanf("%d", &b);
			
			if (prev != 0) {
				cnt[b]++;
				v[prev].push_back(b);
			}
			prev = b;
		}
	}

	TP();

	if (ans.size() == N) {
		for (int i : ans) {
			printf("%d\n", i);
		}
	}
	else {
		printf("0\n");
	}

	return 0;
}