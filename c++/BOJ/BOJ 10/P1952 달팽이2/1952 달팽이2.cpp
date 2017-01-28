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

bool visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int M, N;
int cnt = 0;

int dfs(int x, int y, int dir) {
	cnt++;
	if (cnt == M*N) return 0;
	visit[x][y] = true;
	int nextX = x + dx[dir];
	int nextY = y + dy[dir];
	if (visit[nextX][nextY] == true || nextX >= M || nextX < 0 || nextY >= N || nextY < 0) {
		if (dir == 2) {
			dir = 0;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
		if (dir == 0) {
			dir = 3;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
		if (dir == 1) {
			dir = 2;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
		if (dir == 3) {
			dir = 1;
			return 1 + dfs(x + dx[dir], y + dy[dir], dir);
		}
	}
	return dfs(nextX, nextY, dir);
}

int main() {

	
	scanf("%d %d", &M, &N);
	printf("%d\n", dfs(0, 0, 2));

	return 0;
}