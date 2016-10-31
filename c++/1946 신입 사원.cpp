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


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int T, N;
pair<int, int> arr[100001];
bool visit[100001];

vector<int> v;
queue<int> q;

int main() {
	v.push_back(1);
	v.push_back(2);
	if (v[0] == 1) cout << v[0] << endl;
	if (v[1] == 1) cout << v[1] << endl;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
		}
		sort(arr, arr + N);
		int ans = 1;
		pair<int, int> cur = arr[0];
		for (int i = 1; i < N; i++) {
			if (cur.first < arr[i].first && cur.second < arr[i].second) continue;
			cur = arr[i];
			ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}