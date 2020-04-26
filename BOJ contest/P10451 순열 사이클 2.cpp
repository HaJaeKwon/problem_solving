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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int arr[1001];
bool chk[1001];

void dfs(int pos) {
	if (chk[pos] == true) return;

	chk[pos] = true;
	dfs(arr[pos]);
}

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {

		int N;
		scanf("%d", &N);

		memset(chk, false, sizeof(chk));

		for (int i = 1; i <= N; i++) {
			int a;
			scanf("%d", &arr[i]);
		}
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (chk[i] == false) {
				ans++;
				dfs(i);
			}
		}
		printf("%d\n", ans);

	}

	return 0;
}