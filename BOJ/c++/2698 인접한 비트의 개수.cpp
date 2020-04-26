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

int DP[101][2][101];
int n, k;

int f(int pos, int prev, int cnt) {
	if (pos > n) return 0;
	if (cnt > k) return 0;
	if (pos == n && cnt == k) return 1;

	int& ret = DP[pos][prev][cnt];
	if (ret != -1) return ret;

	ret = 0;
	ret += f(pos + 1, 1, cnt + prev * 1);
	ret += f(pos + 1, 0, cnt + prev * 0);

	return ret;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(DP, -1, sizeof(DP));

		
		scanf("%d %d", &n, &k);
		printf("%d\n", f(1,0,0) + f(1,1,0));
	}

	return 0;
}