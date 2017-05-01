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


#define INF 987654321000
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int A, B, C;
char str1[3001], str2[3001];
int len1, len2;
ll DP[3001][3001];

ll f(int pos1, int pos2) {
	if (pos1 >= len1 || pos2 >= len2) {
		if (pos1 == len1 && pos2 == len2) {
			return 0;
		}
		else if (pos1 != len1) {
			return B * (len1 - pos1);
		}
		else {
			return B * (len2 - pos2);
		}
	}

	ll &ret = DP[pos1][pos2];
	if (ret != -INF) return ret;

	ret = -INF + 1;
	ret = max(ret, B + f(pos1, pos2 + 1));
	ret = max(ret, B + f(pos1 + 1, pos2));
	if (str1[pos1] == str2[pos2]) {
		ret = max(ret, A + f(pos1 + 1, pos2 + 1));
	}
	else {
		ret = max(ret, C + f(pos1 + 1, pos2 + 1));
	}

	return ret;
}

int main() {

	scanf("%d %d %d", &A, &B, &C);
	scanf("%s", str1);
	scanf("%s", str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			DP[i][j] = -INF;
		}	
	}
	printf("%lld\n", f(0, 0));

	return 0;
}