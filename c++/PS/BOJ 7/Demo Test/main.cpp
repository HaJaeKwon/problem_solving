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

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	for (int i = 0; i<A.size(); i++) {
		int sum1 = 0, sum2 = 0;
		for (int j = 0; j < i; j++) {
			sum1 += A[j];
		}
		for (int j = i + 1; j<A.size(); j++) {
			sum2 += A[j];
		}
		if (sum1 == sum2) {
			return i;
		}
	}
}


int main() {

	freopen("input.txt", "r", stdin);

	vector<int> v;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	printf("%d", solution(v));

	return 0;
}