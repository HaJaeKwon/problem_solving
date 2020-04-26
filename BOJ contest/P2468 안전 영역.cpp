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

int N;
int arr[101][101];
bool chk[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y, int water) {
	queue<pair<int, int>> q;
	q.push(mp(x, y));

	while (!q.empty()) {
		int curX, curY;
		tie(curX, curY) = q.front();
		q.pop();

		chk[curX][curY] = true;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || chk[nextX][nextY] == true || arr[nextX][nextY] <= water) continue;
			q.push(mp(nextX, nextY));
		}
	}
}

void dfs(int x, int y, int water) {
	chk[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N || chk[nextX][nextY] == true || arr[nextX][nextY] <= water) continue;
		
		dfs(nextX, nextY, water);
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int ans = 0;

	for (int i = 0; i <= 100; i++) {
		memset(chk, false, sizeof(chk));
		int t = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (chk[j][k] == false && arr[j][k]>i) {
					t++;
					dfs(j, k, i);
				}
			}
		}
		ans = max(ans, t);
		if (t == 0) break;
	}

	printf("%d", ans);

	return 0;
}