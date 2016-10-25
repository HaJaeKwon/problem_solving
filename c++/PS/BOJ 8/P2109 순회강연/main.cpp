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

int N;
pair<int, int> arr[10001];

int main() {

	int maxDay = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = mp(b, a);
		maxDay = max(maxDay, b);
	}

	sort(arr, arr + N);
	priority_queue<int> q;
	int i = N-1;
	int day = maxDay;

	int ans = 0;
	for (; day > 0; day--) {
		while (i >= 0 && day == arr[i].first) {
			q.push(arr[i].second);
			i--;
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	

	printf("%d\n", ans);

	return 0;
}