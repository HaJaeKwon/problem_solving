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

int N;
int arr[1000001];

int cnt[1001];

ll GCD(ll a, ll b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int PRIME[1001];

int main() {

	for (int i = 2; i <= 1000; i++) {
		if (PRIME[i] == 0) {
			for (int j = i+i; j <= 1000; j += i) {
				PRIME[j] = 1;
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < N; i++) {
			int t = arr[i];
			for (int j = 2; j <= t; j++) {
				if (PRIME[j] == 1) continue;
				int c = 0;
				while (arr[i] % j == 0) {
					c++;
					arr[i] /= j;
				}
				if (cnt[j] < c) {
					cnt[j] = c;
				}
			}

		}

		ll ans = 1;
		for (int i = 2; i <= 1000; i++) {
			if (PRIME[i] == 1) continue;
			if (cnt[i] != 0) {
				for (int j = 0; j < cnt[i]; j++) {
					ans = (ans*i) % mod;
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}