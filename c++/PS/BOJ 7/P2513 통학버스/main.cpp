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

int N, K, S;
int arr[100001];
int start = INF, last = 0;

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d%d%d", &N, &K, &S);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a] = b;
		start = min(start, a);
		last = max(last, a);
	}

	int ans = 0;
	int k = 0;
	for (int i = start; i < S; i++) {
		if (arr[i] > 0) {
			if (arr[i] % K == 0) {
				ans += (arr[i] / K) * (S - i) * 2;
			}
			else {
				ans += (arr[i] / K + 1) * (S - i) * 2;
			}
			k += arr[i] % K;
			if (k == 0) continue;
			for (int j = i+1; j < S && k<K; j++) {
				if (arr[j] > 0) {
					int r = min(arr[j] + k, K) - k;
					//r = min(r, arr[j]);
					arr[j] -= r;
					k += r;
					if (k >= K) break;
				}
			}
			k = 0;
		}
	}

	for (int i = last; i > S; i--) {
		if (arr[i] > 0) {
			if (arr[i] % K == 0) {
				ans += (arr[i] / K) * (i -S) * 2;
			}
			else {
				ans += (arr[i] / K + 1) * (i-S) * 2;
			}
			k += arr[i] % K;
			if (k == 0) continue;
			for (int j = i-1; j > S && k<K; j--) {
				if (arr[j] > 0) {
					int r = min(arr[j] + k, K) - k;
					//r = min(r, arr[j]);
					arr[j] -= r;
					k += r;
					if (k >= K) break;
				}
			}
			k = 0;
		}
	}

	printf("%d\n", ans);
	

	return 0;
}