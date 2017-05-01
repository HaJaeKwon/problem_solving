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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int DP[10001];
int coin[101];
int cnt[101];
int N, K;

int main() {

	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d%d", &coin[i], &cnt[i]);
	}

	DP[0] = 1;
	
	for (int i = 0; i < K; i++) {
		for (int j = N; j >= 0; j--) {
			for (int k = 1; k <= cnt[i]; k++) {
				if (coin[i] * k > N) break;
				if (j - coin[i] * k < 0) continue;
				DP[j] += DP[j - coin[i] * k];
			}
		}
	}

	printf("%d\n", DP[N]);
	

	return 0;
}