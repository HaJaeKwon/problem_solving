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

int storm[10001][10001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int i, int dir, int cnt, int level) {
	if()
	storm[5000 + x][5000 + y] = i;
	if (dir == 0) dfs(x + dx[i], y + dy[i], i + 1, 3);
	if (dir == 1) dfs(x + dx[i], y + dy[i], i + 1, 3);
	if (dir == 0) dfs(x + dx[i], y + dy[i], i + 1, 3);
	if (dir == 0) dfs(x + dx[i], y + dy[i], i + 1, 3);
	
}

int main() {

	dfs(0, 0, 1, 0);
	

	return 0;
}