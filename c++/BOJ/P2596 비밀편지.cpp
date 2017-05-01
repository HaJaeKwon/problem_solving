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

map<char, string> m = {
	{'A', "000000"},
	{'B', "001111"},
	{'C', "010011"},
	{'D', "011100"},
	{'E', "100110"},
	{'F', "101001"},
	{'G', "110101"},
	{'H', "111010"}
};
int N;
string str;
string ans;

int checkNumber(string str1, string str2) {
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (str1[i] != str2[i]) cnt++;
	}
	if (cnt >= 2) return 0;
	return 1;
}

int main() {

	scanf("%d", &N);
	cin >> str;

	for (int i = 0; i < str.length(); i += 6) {
		int cnt = 0;
		for (auto a : m) {
			int t = checkNumber(a.second, str.substr(i, i + 6));
			if (t == 1) {
				ans.push_back(a.first);
				cnt += t;
			}
		}
		if (cnt != 1) {
			printf("%d\n", i / 6 + 1);
			return 0;
		}
	}
	printf("%s\n", ans.c_str());

	return 0;
}