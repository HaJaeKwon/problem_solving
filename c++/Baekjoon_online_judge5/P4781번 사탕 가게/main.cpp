#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M;
long long DP[11111];
int c[11111];
int p[11111];

// �������� knapsack ���� !!
// knapsack������ ���������� ���������� ����for������ �ذᰡ���ϴ�.
// �ٱ����� ������ ������ �ƴ϶� ���� �;� �Ѵ�.
// ���� ���� ����Ҷ��� 0���� M���� �߿����� �ִ� ��ġ�� ��� !!
// ������ �Ҽ����� �����Ѵ�. �Ҽ����� 100�� *�Ҷ��� �ݵ�� +0.5 ����ġ�� ������� �Ѵ�. !!!
// �׸��� ���̽��� �������� -> �Ź� �ʱ�ȭ�� ����� �Ѵ�. !!!

int main() {

	while(1) {
		double tm;
		cin>>N>>tm;
		if(N==0 && tm==0.00) break;
		M = (int)(tm*100+0.5);
		for(int i=0; i<N; i++) {
			cin>>c[i]>>tm;
			p[i] = (int)(tm*100+0.5);
		}
		memset(DP,0,sizeof(DP));
		for(int i=1; i<=M; i++) {
			for(int j=0; j<N; j++) {
				if(i-p[j]>=0) {
					DP[i] = max(DP[i], DP[i-p[j]]+c[j]);
				}
			}
		}
		long long ans=0;
		for(int i=1; i<=M; i++)
			ans = max(ans, DP[i]);
		cout<<ans<<endl;
	}

	return 0;
}