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

char str1[1010], str2[1010];
int DP[1010][1010];
int len, len1, len2;

int f(int pos1, int pos2) {
	if (pos1 >= len1 || pos2 >= len2) return 0;
	
	int& ret = DP[pos1][pos2];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, f(pos1 + 1, pos2));
	ret = max(ret, f(pos1, pos2 + 1));
	if (str1[pos1] == str2[pos2]) {
		ret = max(ret, 1 + f(pos1 + 1, pos2 + 1));
	}

	return ret;
}

void print_path() {
	int pos1 = 0, pos2 = 0, offset, cnt=0;

	while (cnt < len) {
		offset = 0;
		while (DP[pos1][pos2] == DP[pos1][pos2 + offset]) {
			offset++;
		}
		offset--;
		pos2 += offset;

		offset = 0;
		while (DP[pos1][pos2] == DP[pos1 + offset][pos2]) {
			offset++;
		}
		offset--;
		pos1 += offset;

		printf("%c", str1[pos1]);
		cnt++, pos1++, pos2++;
	}
	printf("\n");
}

int main() {

	scanf("%s", str1);
	scanf("%s", str2);

	memset(DP, -1, sizeof(DP));
	len1 = strlen(str1);
	len2 = strlen(str2);
	if (len1 < len2) {
		swap(str1, str2);
		swap(len1, len2);
	}

	len = f(0, 0);
	printf("%d\n", len);
	print_path();

	return 0;
}