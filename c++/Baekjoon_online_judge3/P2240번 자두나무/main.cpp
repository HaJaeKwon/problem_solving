#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int T,W,arr[1010],DP[1010][40][3];

// ���̻� �����ϼ������� �ܼ��� return 0�� �ϴ°� �ƴ϶�
// �� ��ġ���� ���� �� �ִ� ��� �ڵθ� ���� ������Ѵ�.

int f(int t, int w, int p) {
	if(t==T-1) return (arr[t]==p)?1:0;
	if(w==W) {
		int ans=0;
		for(int i=t; i<T; i++)
			if(arr[i]==p) ans++;
		return ans;
	}

	int ret=DP[t][w][p];
	if(ret==-1) {
		ret=0;
		if(arr[t]==p)
			ret=1;
		ret += max(f(t+1,w,p), f(t+1,w+1,(p+1)%2));
		DP[t][w][p] = ret;
	}
	return ret;
}

int main() {
	int a;
	scanf("%d %d", &T, &W);
	for(int i=0; i<T; i++) {
		scanf("%d", &a);
		arr[i]=a-1;
	}
	
	memset(DP,-1,sizeof(DP));
	int ans=f(0,0,0);
	memset(DP,-1,sizeof(DP));
	ans=max(ans,f(0,1,1));

	printf("%d\n", ans);

	return 0;
}