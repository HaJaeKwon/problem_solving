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
pair<int, string> p[100001];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		string str;
		cin >> a >> str;
		p[i] = mp(a, str);
	}

	stable_sort(p, p + N, [](pair<int,string> a, pair<int, string> b) {
		return a.first < b.first;
	});

	for (int i = 0; i < N; i++) {
		auto a = p[i];
		printf("%d %s\n", a.first, a.second.c_str());
	}

	return 0;
}