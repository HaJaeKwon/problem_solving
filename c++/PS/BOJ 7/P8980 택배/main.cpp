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

struct P {
	int src, dest, box;
	P() {}
	P(int a, int b, int c) : src(a), dest(b), box(c) {}
};
int sum[2010];


int main() {

	int N, C, M;
	scanf("%d %d %d", &N, &C, &M);

	vector<P> arr(M);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = P(a, b, c);
	}

	sort(arr.begin(), arr.end(), [](const P &a, const P &b) {
		if (a.dest == b.dest) {
			return a.src < b.src;
		}
		else {
			return a.dest < b.dest;
		}
	});

	int cur = 0;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int m = 0;
		for (int j = arr[i].src; j < arr[i].dest; j++) {
			m = max(m, sum[j]);
		}
		m = min(C - m, arr[i].box);
		for (int j = arr[i].src; j < arr[i].dest; j++) {
			sum[j] += m;
		}
		ans += m;
	}

	printf("%d\n", ans);

	return 0;
}