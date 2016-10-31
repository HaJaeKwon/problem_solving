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


int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> v(n + 1, 0);
		vector<pair<int, int>> edges;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a]++;
			v[b]++;
			edges.push_back(mp(a, b));
		}
		int K = 0, kCnt = 0;
		for (int i : v) {
			if (kCnt < i) {
				kCnt = i;
			}
		}
		int i = 0;
		for (auto a : edges) {
			printf("%d %d %d\n", a.first, a.second, i % (kCnt + 1) + 1);
			i++;
		}
	}

	return 0;
}