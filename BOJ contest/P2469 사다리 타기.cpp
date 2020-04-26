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

int K,N;
char arr[1100][1100];
char ans[1100];
int posMark;
char dest[1100];
char failAns[1100];

int process(int x, int dir) {
	if (dir == 2) {
		int name = x;
		for (int y = 0; y < K; y++) {
			if (arr[y][x] == '-') {
				x--;
			}
			else if (arr[y][x+1] == '-') {
				x++;
			}
		}
		if (dest[x] - 'A' != name) {
			return -1;
		}
		return 1;
	}


	int y = dir == 1 ? 0 : K - 1;

	while (y != posMark) {

		if (arr[y][x] == '-') {
			x--;
		}
		else if (arr[y][x+1] == '-') {
			x++;
		}

		y += dir;
	}

	return x;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	scanf("%s", dest);

	for (int i = 0; i < K; i++) {
		scanf("%s", arr[i]+1);
		if (arr[i][1] == '?') {
			posMark = i;
		}
	}

	bool ok = true;
	for (char i = 'A'; i < 'A' + N; i++) {

		int pos1 = process(i - 'A', 1);

		int pos2 = 0;
		for (int j = 0; j < N; j++) {
			if (dest[j] == i) {
				pos2 = process(j, -1);
				break;
			}
		}
		
		// ? ��ٸ� ä���
		if (abs(pos1 - pos2) >= 2) {
			ok = false;
			break;
		}
		if (pos1 == pos2) {
			ans[pos1] = ans[pos1 + 1] = '*';
		}
		else if (pos1 < pos2) {
			ans[pos1] = '*';
			ans[pos2] = '-';
		}
		else {
			ans[pos1] = '-';
			ans[pos2] = '*';
		}
	}
	if (ok) {
		strcpy(arr[posMark]+1, ans+1);

		for (char i = 'A'; i < 'A' + N; i++) {
			if (process(i-'A', 2)==-1) {
				ok = false;
				break;
			}
		}
	}
	if (ok) {
		ans[N] = '\0';
		printf("%s\n", ans + 1);
	}
	else {
		for (int i = 0; i < N - 1; i++) {
			failAns[i] = 'x';
		}
		printf("%s\n", failAns);
	}
	

	return 0;
}