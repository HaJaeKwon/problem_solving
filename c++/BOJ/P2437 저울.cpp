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
int arr[1001];

bool dfs(int dest, int pos, int sum) {
	if (sum > dest) return false;
	if (sum == dest) return true;
	if (pos >= N) return false;

	return dfs(dest, pos + 1, sum + arr[pos]) || dfs(dest, pos + 1, sum);
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + N);

	ll sum = arr[0];

	if (sum != 1) {
		printf("1\n");
		return 0;
	}

	for (int i = 1; i < N; i++) {
		if (arr[i] <= sum+1) {
			sum += arr[i];
		}
		else {
			break;
		}
		
	}

	printf("%lld\n", sum + 1);

	return 0;
}