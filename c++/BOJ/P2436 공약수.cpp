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

int A, B;

ll GCD(ll A, ll B) {
	if (B == 0) return A;
	return GCD(B, A%B);
}

int main() {

	scanf("%d %d", &A, &B);


	if (A == B) {
		printf("%d %d\n", A, B);
		return 0;
	}

	ll ans1, ans2;
	ll a1 = A, a2 = B/A;

	ans1 = A, ans2 = B;

	ll r = B / A;

	for (int i = 1; i <= r; i++) {
		
		if (r%i == 0) {
			ll temp1 = A*i;
			ll temp2 = A*(r / i);

			if (temp1 > temp2) break;

			if (GCD(min(temp1,temp2), max(temp1, temp2)) != A) continue;
			if ((temp1*temp2) / GCD(min(temp1, temp2), max(temp1, temp2)) != B) continue;

			if (temp1 + temp2 < ans1 + ans2) {
				ans1 = temp1;
				ans2 = temp2;
			}
		}
	}
	printf("%lld %lld\n", min(ans1, ans2), max(ans1, ans2));

	return 0;
}