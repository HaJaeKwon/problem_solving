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

int N;
int DP[101][2001];
int coin[21];
int bright[21];

int f(int pos, int hp) {
	if (hp >= 100 || pos>=N) return 0;

	int& ret = DP[pos][hp];
	if (ret != -1) return ret;

	ret = f(pos + 1, hp);
	if (hp + coin[pos] < 100) {
		ret = max(ret, bright[pos] + f(pos + 1, hp + coin[pos]));
	}
	return ret;
}

int main() {

	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &coin[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &bright[i]);
	}

	memset(DP, -1, sizeof(DP));

	printf("%d\n", f(0, 0));



	return 0;
}