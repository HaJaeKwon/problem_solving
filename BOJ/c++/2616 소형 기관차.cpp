#include <iostream>
#include <algorithm>
using namespace std;

int N,m,arr[50010],DP[3][50010];

// DP �������ϴ¹� !
// ���� DP[i] ��� �ϸ� i������ �ִ밪? �̷������� �����ϴµ� �׷�������
// DP[i]������ ������.��� ��������
// �׷� �� ������ ������ ���Ҷ� �� ������ ������ i������ �����ذ� �ֱ� ������ �����پ��� �ȴ�.

void solve() {
	DP[0][0]=DP[1][0]=DP[2][0]=0;

	for(int i=0; i<3; i++) {
		for(int j=(i+1)*m-1; j<N; j++) {
			if(i==0) {
				DP[i][j]=max(DP[i][j-1],arr[j]-arr[j-m]);
			} else {
				DP[i][j]=max(DP[i][j-1], DP[i-1][j-m]+arr[j]-arr[j-m]);
			}
		}
	}
}

int main() {
	int a;
	scanf("%d", &N);
	scanf("%d", &arr[0]);
	for(int i=1; i<N; i++) {
		scanf("%d", &a);
		arr[i]=arr[i-1]+a;
	}
	scanf("%d", &m);

	solve();

	printf("%d\n", DP[2][N-1]);

	return 0;
}