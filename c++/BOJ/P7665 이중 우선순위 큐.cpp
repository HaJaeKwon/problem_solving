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


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

bool check[1000006];

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		ll n;
		char c;
		scanf("%d", &k);

		memset(check, 0, sizeof(check));
		priority_queue<pair<ll, int>> mx, mn;

		for (int i = 0; i < k; i++) {
			scanf("\n%c %lld", &c, &n);
			if (c == 'I') {
				mx.push(mp(n, i));
				mn.push(mp(-n, i));
			}
			else {
				while (!mx.empty() && check[mx.top().second]) mx.pop();
				while (!mn.empty() && check[mn.top().second]) mn.pop();

				if (n == 1) {
					if (!mx.empty()) {
						check[mx.top().second] = true;
						mx.pop();
					}
				}
				else {
					if (!mn.empty()) {
						check[mn.top().second] = true;
						mn.pop();
					}
				}

			}
			

		}
		while (!mx.empty() && check[mx.top().second]) mx.pop();
		while (!mn.empty() && check[mn.top().second]) mn.pop();
		if (mx.empty() || mn.empty()) {
			printf("EMPTY\n");
		}
		else {
			printf("%lld %lld\n", mx.top().first, -mn.top().first);
		}
	}

	return 0;
}