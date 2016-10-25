#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 987654321

int N;
pair<int, int> arr[510];
int DP[510][510];

int f(int left, int right) {
	if(left+1 == right) return arr[left].first * arr[left].second * arr[right].second;
	if(left >= right) return 0;
	

	int &ret = DP[left][right];
	if(ret != -1) return ret;
	
	ret = INF;
	//ret = arr[left].first*arr[left].second*arr[right].second + f(left+1, right);
	for(int k=left; k<right; k++) {
		// f(left,k)+f(k+1,right) �� ���� �ƴ϶� �ᱹ �� ����� ���ؾ� �ϱ� ������
		// �ΰ��� ���ϴ� ����ġ�� ���� �־�� �Ѵ�. !!
		ret = min(ret, f(left,k)+f(k+1,right)+arr[left].first*arr[k].second*arr[right].second);
	}
	//ret = min(ret, f(left, right-1) + arr[left].first*arr[right].first*arr[right].second);

	return ret;
}

int main() {

	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		arr[i] = make_pair(a,b);
	}

	memset(DP, -1, sizeof(DP));

	printf("%d\n", f(1,N));

	return 0;
}