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

#define INF 98765432100
#define BOUND 100000000
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	sort(A.begin(), A.end());

	if (A.size() == 1) return -2;

	ll ans = INF;
	for (int i = 1; i < A.size(); i++) {
		ans = min(ans, (ll)A[i] - A[i - 1]);
	}
	if (ans > BOUND) return -1;
	return ans;
}

int main() {

	vector<int> v;
	freopen("input.txt", "r", stdin);
	int N, a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}

	printf("%d", solution(v));


	return 0;
}