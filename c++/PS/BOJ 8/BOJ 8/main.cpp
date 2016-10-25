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

int N, S;
pair<int,int> p[300010];
int DP[300010];
int h[300010];

int f(int pos) {

	if (pos == N) return 0;

	int& ret = DP[pos];
	if (ret != -1) return ret;

	ret = f(pos + 1);
	int next = lower_bound(h, h + N, p[pos].first + S) - h;
	ret = max(ret, f(next) + p[pos].second);

	return ret;
}


int main() {

	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p[i] = mp(a, b);
		h[i] = a;
	}
	sort(p, p + N);
	sort(h, h + N);

	memset(DP, -1, sizeof(DP));

	printf("%d\n", f(0));

	return 0;
}