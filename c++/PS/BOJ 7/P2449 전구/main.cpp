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

int N, K;
int DP[201][201];
int arr[201];

int f(int left, int right) {

	bool ok = true;
	for (int i = left; i <= right; i++) {
		if (arr[i] != arr[left]) {
			ok = false;
			break;
		}
	}

	int& ret = DP[left][right];
	if (ret != -1) return ret;

	ret = INF;

	if (ok) return ret=0;

	


}

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	memset(DP, -1, sizeof(DP));

	printf("%d\n", f(0, N - 1));

	return 0;
}