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

int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int kx, ky, sx, sy;
map<string, int> m = {
	{ "R", 0 },
	{ "L", 1 },
	{ "B", 2 },
	{ "T", 3 },
	{ "RT", 6 },
	{ "LT", 7 },
	{ "RB", 4 },
	{ "LB", 5 }
};

int main() {

	string str;
	int N;
	cin >> str;
	kx = str[1];
	ky = str[0];
	cin >> str;
	sx = str[1];
	sy = str[0];
	cin >> N;
	while (N--) {
		cin >> str;
		int nextKX, nextKY;
		nextKX = kx + dx[m[str]];
		nextKY = ky + dy[m[str]];
		if (nextKX < '1' || nextKX > '8' || nextKY < 'A' || nextKY > 'H') continue;
		if (nextKX == sx && nextKY == sy) {
			int nextSX = sx + dx[m[str]];
			int nextSY = sy + dy[m[str]];
			if (nextSX < '1' || nextSX > '8' || nextSY < 'A' || nextSY > 'H') continue;
			sx = nextSX;
			sy = nextSY;
		}
		kx = nextKX;
		ky = nextKY;
	}

	cout << (char)ky << (char)kx << endl;
	cout << (char)sy << (char)sx << endl;

	return 0;
}