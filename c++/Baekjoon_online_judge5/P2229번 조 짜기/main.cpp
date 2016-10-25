#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,DP[1001][2],arr[1001];

int solve(int num, int minV, int maxV) {
	if(num>N) return maxV-minV;

	// DP�� �Ἥ Ǯ�� ����
	// DP�� ���� ������ �ϴ� �����ΰ� ���� ��....
	// DP�� Ǯ�⿣ ��ȭ�� ��ü�� �߸��Ǿ��ٰ� ������. �ϴ� �������� �κп��� ������ �������� ����.
	int ret1 = DP[num][0];
	if(ret1 == -1) ret1 = solve(num+1, arr[num], arr[num]) + (maxV-minV);
	int ret2 = DP[num][1];
	if(ret2 == -1) ret2 = solve(num+1, min(minV,arr[num]), max(maxV,arr[num]));

	return max(ret1,ret2);
}

int main() {

	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);

	memset(DP,-1,sizeof(DP));
	int ans = solve(1,arr[1], arr[1]);

	printf("%d\n", ans);

	return 0;
}