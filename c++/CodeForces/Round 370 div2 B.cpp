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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int cnt['Z' + 1];

int main() {

	string str;
	cin >> str;

	if (str.length() % 2 == 1) {
		printf("-1\n");
	}
	else {
		for (char c : str) {
			cnt[c]++;
		}
		int ans = 0;
		if ((cnt['L'] + cnt['R']) % 2 == 1 && (cnt['U'] + cnt['D']) % 2 == 1) {
			ans = (abs(cnt['L'] - cnt['R']) + abs(cnt['U'] - cnt['D'])) / 2;
		}
		else {
			ans = abs(cnt['L'] - cnt['R'])/2 + abs(cnt['U'] - cnt['D'])/2;
		}
		printf("%d\n", ans);
	}


	return 0;
}