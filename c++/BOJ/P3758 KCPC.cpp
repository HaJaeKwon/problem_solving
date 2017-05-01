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

int score[101][101];
struct Team {
	int total, cnt, time, idx;
	Team() {}
	Team(int a, int b, int c, int d) : total(a), cnt(b), time(c), idx(d) {}
};

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {

		int n, k, t, m, i, j, s;
		scanf("%d %d %d %d", &n, &k, &t, &m);
		memset(score, 0, sizeof(score));
		
		vector<Team> team(n + 1, Team(0, 0, 0, 0));
		for (int ii = 1; ii <= n; ii++) {
			team[ii].idx = ii;
		}

		for (int ii = 0; ii < m; ii++) {
			scanf("%d %d %d", &i, &j, &s);
			team[i].cnt++;
			team[i].time = ii;
			score[i][j] = max(score[i][j], s);
		}
		for (int ii = 1; ii <= n; ii++) {
			int sum = 0;
			for (int jj = 1; jj <= k; jj++) {
				sum += score[ii][jj];
			}
			team[ii].total = sum;
		}
		sort(team.begin(), team.end(), [](Team A, Team B) {
			if (A.total == B.total) {
				if (A.cnt == B.cnt) {
					return A.time < B.time;
				}
				return A.cnt < B.cnt;
			}
			return A.total > B.total;
		});
		int ans = 0;
		for (int ii = 1; ii <= n; ii++) {
			if (team[ii].idx == t) {
				ans = ii;
				break;
			}
		}
		printf("%d\n", ans+1);
	}

	return 0;
}