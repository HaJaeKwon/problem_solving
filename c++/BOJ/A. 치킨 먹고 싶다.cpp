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


int main() {

	int T;
	scanf("%d", &T);

	int P, M, F, C;
	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d", &P, &M, &F, &C);

		int coupon = (M / P)*C;
		int one = coupon / F;
		int ans = one;
		coupon = (coupon%F) + ((coupon / F)*C);

		while (coupon / F > 0) {
			ans += coupon / F;
			coupon = (coupon%F) + ((coupon / F)*C);
		}

		printf("%d\n", ans - one);
	}

	return 0;
}