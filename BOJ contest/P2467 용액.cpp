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
int arr[100001];

int main() {

	freopen("input.txt", "r", stdin);

	vector<int> listPlus;
	vector<int> listMinus;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (a < 0) {
			listMinus.push_back(a);
		}
		else {
			listPlus.push_back(a);
		}
	}

	int ans, ans1, ans2;

	if (listMinus.size() == 0) {
		ans1 = listPlus[0];
		ans2 = listPlus[1];
	}
	else if (listPlus.size() == 0) {
		ans1 = listMinus[N-2];
		ans2 = listMinus[N-1];
	}
	else {
		ans = INF;
		for (int i = 0; i < listMinus.size(); i++) {
			int cur = listMinus[i];
			int lb = 0, ub = listPlus.size() - 1;
			int md;
			while (lb <= ub) {

				md = (lb + ub) / 2;

				if (cur + listPlus[md] < 0) {
					lb = md + 1;
				}
				else if (cur + listPlus[md] > 0) {
					ub = md - 1;
				}
				else {
					ans = 0;
					ans1 = cur;
					ans2 = listPlus[md];

					printf("%d %d", ans1, ans2);

					return 0;
				}

				if (abs(cur + listPlus[md]) < ans) {
					ans = abs(cur + listPlus[md]);
					ans1 = cur;
					ans2 = listPlus[md];
				}
			}

			
		}
	}



	printf("%d %d", ans1, ans2);


	return 0;
}