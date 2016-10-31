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

bool dfs(int n, int a, int cnt) {
	if (a == 0 && cnt == 3) return true;
	if (cnt > 3 || n == 0 || a <= 0) return false;

	bool ok = dfs(n - 1, a, cnt);
	ok |= dfs(n - 1, a - (n*(n + 1) / 2), cnt + 1);
	ok |= dfs(n - 1, a - (n*(n + 1)), cnt + 2);
	ok |= dfs(n - 1, a - ((n*(n + 1) / 2) * 3), cnt + 3);

	return ok;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int a;
		scanf("%d", &a);

		int n = 1;
		while (n*(n+1)/2 < a) {
			n++;
		}

		bool ok = dfs(n, a, 0);

		ok ? printf("1\n") : printf("0\n");
	}

	return 0;
}