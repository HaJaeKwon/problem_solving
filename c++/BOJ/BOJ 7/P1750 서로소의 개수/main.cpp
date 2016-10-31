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
#define mod 10000003
#define mt make_tuple
#define mp make_pair
typedef long long ll;

ll DP[110][100010];
int N, arr[110];

int GCD(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a%b;
		a = t;
	}
	return a;
	/*
	if (b == 0) return a;
	else return GCD(b, a%b);
	*/
}

ll f(int pos, int value) {
	if (pos >= N) {
		if (value == 1) return 1;
		return 0;
	}

	ll &ret = DP[pos][value];
	if (ret != -1) return ret;

	ret = 0;

	ll t;

	if (value == 0) {
		t = ret + f(pos + 1, arr[pos]);
		if (t > mod) t %= mod;
		ret = t;
	}
	else {
		t = ret + f(pos + 1, GCD(value, arr[pos]));
		if (t > mod) t %= mod;
		ret = t;
	}

	t = ret + f(pos + 1, value);
	if (t > mod) t %= mod;
	ret = t;

	return ret;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	memset(DP, -1, sizeof(DP));
	sort(arr, arr + N);

	printf("%lld\n", f(0, 0));

	return 0;
}