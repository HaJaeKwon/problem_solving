#include <iostream>
using namespace std;

int w[100][100],n;
int sum[100];

void TS(void) {
	int rest = n;
	int i,j;
	while(rest--) {
		for(i=0; i<n; i++) {
			if(sum[i]==0) break;
		}
		// ���� ó���Ǵ� �۾�
		sum[i]=-1;
		cout<<i+1<<" ";

		// ���� �۾��� ���� �۾��� �հ迡 ������ �۾��鿡 ���ؼ�
		// ���� �۾� �հ踦 1�� ���ҽ�Ų��.
		for(j=0; j<n; j++) {
			if(w[i][j]) sum[j]--;
		}
	}
}

int main() {
	int m,a,b;
	cin>>n>>m;
	while(m--) {
		cin>>a>>b;

		w[a-1][b-1]=1;
		sum[b-1]++;
	}

	TS();

	return 0;
}