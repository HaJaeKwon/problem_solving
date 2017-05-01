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

char str1[4001], str2[4001];
int DP[4001][4001];
int len1, len2;
int ans;

int f(int pos1, int pos2) {
	if (pos1 >= len1 || pos2 >= len2) return 0;

	int& ret = DP[pos1][pos2];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, f(pos1 + 1, pos2));
	ret = max(ret, f(pos1, pos2 + 1));
	if (str1[pos1] == str2[pos2]) ret = max(ret, 1 + f(pos1 + 1, pos2 + 1));

	ans = max(ans, ret);
	return ret;
}

int main() {

	scanf("%s", str1+1);
	scanf("%s", str2+1);
	str1[0] = '0';
	str2[0] = '0';
	len1 = strlen(str1);
	len2 = strlen(str2);

	//memset(DP, -1, sizeof(DP));

	//f(0, 0);

	for (int i = 1; i < len1; i++) {
		for (int j = 1; j < len2; j++) {
			if (str1[i] == str2[j]) {
				DP[i][j] = 1 + DP[i - 1][j - 1];
				ans = max(ans, DP[i][j]);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}