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

map<char, int> m1;
map<int, int> m2;

int main() {
	char c;
	int n;
	for (int i = 0; i < 5; i++) {
		cin >> c >> n;
		m1[c]++;
		m2[n]++;
	}

	// Rule 1
	if (m1.size() == 1) {
		bool ok = true;
		auto a = m2.begin();
		auto it = m2.begin();
		it++;
		for (; it != m2.end(); a++,it++) {
			if (it->first - a->first != 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			it = m2.end();
			it--;
			int ans = 900 + it->first;
			printf("%d\n", ans);
			return 0;
		}
		else {
			// Rule 4
			it = m2.end();
			it--;
			int ans = 600 + it->first;
			printf("%d\n", ans);
			return 0;
		}
	}

	if (m2.size() == 2) {
		for (auto a : m2) {
			if (a.second == 4) {
				int ans = 800 + a.first;
				printf("%d\n", ans);
				return 0;
			}
			if (a.second == 3) {
				auto a1 = m2.begin();
				auto a2 = m2.begin();
				a2++;
				int ans = 700;
				if (a1->second == 3) {
					ans += 10 * a1->first;
				}
				else {
					ans += a1->first;
				}

				if (a2->second == 3) {
					ans += 10 * a2->first;
				}
				else {
					ans += a2->first;
				}
				printf("%d\n", ans);
				return 0;
			}
		}
	}

	if (m2.size() == 5) {
		bool ok = true;
		auto a = m2.begin();
		auto it = m2.begin();
		it++;
		for (; it != m2.end(); a++, it++) {
			if (it->first - a->first != 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			// Rule 5
			it = m2.end();
			it--;
			int ans = 500 + it->first;
			printf("%d\n", ans);
			return 0;
		}
	}

	int three = 0;
	int two = 0;
	int threeNumber = 0;
	int twoNumber1 = 0;
	int twoNumber2 = 0;

	for (auto a : m2) {
		if (a.second == 3) {
			three++;
			threeNumber = max(threeNumber, a.first);
		}
		if (a.second == 2) {
			two++;
			if (twoNumber1 == 0) twoNumber1 = a.first;
			else {
				twoNumber2 = max(a.first, twoNumber1);
				twoNumber1 = min(a.first, twoNumber1);
			}
		}
	}
	int ans = 0;
	if (three > 0) {
		ans = 400 + threeNumber;
	}
	else if (two == 2) {
		ans = 300 + 10 * twoNumber2 + twoNumber1;
	}
	else if (two == 1) {
		ans = 200 + twoNumber1;
	}
	else {
		auto it = m2.end();
		it--;
		ans = 100 + it->first;
	}

	printf("%d\n", ans);



	return 0;
}