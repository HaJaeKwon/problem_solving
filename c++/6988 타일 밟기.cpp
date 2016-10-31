#include <iostream>
#include <algorithm>
using namespace std;

int N;
int C[1000010],arr[3010];

// ���� �ִ밡 �Ǵ� �ִ� ���������� �Ϲ������� ���ҷ���
// N^3�̴�. ���⼭ ���ݴ� ���� ���� �ؽ��� ��������ν�
// N^2*logN���� ���� �˰����̴�.

int main() {

	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &arr[i]);
		C[arr[i]]++;
	}
	int ans=0;
	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
			int sum=0, cnt=0;
			for(int d=arr[i]; d<1000001; d+=arr[j]-arr[i]) {
				if(C[d]==0) break;
				sum += d, cnt++;
			}
			if(ans<sum && cnt>2) ans=sum;
		}
	}

	printf("%d\n", ans);

	return 0;
}