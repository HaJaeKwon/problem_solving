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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int v[101][101];

int main() {

	int n, m, from, to, cost;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		if (v[from][to] != 0 && v[from][to] < cost) continue;
		v[from][to] = cost;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (v[i][k] == 0 || v[k][j] == 0) continue;
				if (v[i][j] == 0 && v[i][k]>0 && v[k][j] > 0) {
					v[i][j] = v[i][k] + v[k][j];
					continue;
				}
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}

	return 0;
}