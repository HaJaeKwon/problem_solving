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
#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

// �Է¹޴� ���� 10^9 �̰� ���� ���� �װ͵��� ���ϴ� �����̶�� ���� ll �ϼ� �ִ�


int main() {

	int n, x;
	ll ans1=0, ans2=0;
	scanf("%d %d", &n, &x);
	ans1 = x;
	for (int i = 0; i < n; i++) {
		char c;
		int d;
		scanf(" %c %d", &c, &d);
		if (c == '+') ans1 += d;
		else {
			if (ans1 >= d) {
				ans1 -= d;
			}
			else {
				ans2++;
			}
		}
	}
	printf("%I64d %I64d\n", ans1, ans2);

	return 0;
}