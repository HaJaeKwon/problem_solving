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


int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	long long ans1 = min(A[0], A[1]);
	long long ans2 = max(A[0], A[1]);

	for (int i = 2; i < A.size(); i++) {

		ans1 = min(ans1, (long long)A[i]);
		ans2 = max(ans2, (long long)A[i]);

	}

	int ans = ans2 - ans1;
	return ans;
}

int main() {

	freopen("input.txt", "r", stdin);

	vector<int> v;
	int N, a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}

	printf("%d", solution(v));



	return 0;
}