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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

ll x;
int n, d;
int a[100005], b[100005], one[100005];

ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
void initAB() {
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for (int i = 0; i < n; i++) {
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}

int main() {

	scanf("%d %d %I64d", &n, &d, &x);
	initAB();


	/*
	A�迭�� � ������ ����Ǵ��� B�迭���� 0�� 1�ۿ� ����. Ci �� ����Ǵ� ���ҵ��� A�迭�� i ���� ������ ���ҵ� �� B�迭�� 1�� ������ ���� �����ȴٴ� ���̴�.
	�׸��� i�� �����Ǹ� B�迭�� j��°�� �ڵ����� �����ȴ�. �̸��� Ai ������ ���ҵ��� �������� �����ص� ���¿��� ���� ���� 1�� �������� ����
	C�迭�� ���Ұ� �ȴٴ� ���̴�.

	���⼭ d�� 1�϶� ����ó���� ���־�� �ϴ� �Ͱ���.
	�� �������� d�� 1�̸� B�迭�� ���� 1�� �� 1���� �����.
	��ġ�� �� �� ������ �� �༮�� ã�µ� set�� ���� �ͺ��� �迭�� ���°� �����⿡
	d�� �������� �迭�� ���� �ؾ� �� �� ����.
	*/

	int vn = 0;
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			one[++vn] = i;
		}
	}

	set<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		s.insert(mp(-a[i], i));
		int ans = 0;
		if (d == 1) {
			for (int j = 1; j <= vn; j++) {
				if (one[j] > i) break;
				ans = max(ans, a[i - one[j]]);
			}
		}
		else {
			for (auto ss : s) {
				if (b[i - ss.second] == 1) {
					ans = max(ans, -ss.first);
					break;
				}
			}
		}

		printf("%d ", ans);
	}

	return 0;
}