#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 310

// upper bound�� ������� ������ ����Ѵ�.
// max���� �Է����� �۵����� ���� �� �ֱ� �����̴�.
// �׸��� ���ǿ� ���� return false, return true�� �� �����ؾ� �Ѵ�.
// �̰ſ� ���� ���� ���� �������� �������� �����Ǳ� �����̴�.


int N,M,lb,ub,m,arr[MAXN],cnt[MAXN],temp[MAXN];

bool promise(int x) {
	int groupCnt=1,sum=0;
	fill(temp,temp+M,0);
	for(int i=0; i<N; i++) {
		if(groupCnt>M) return false;
		if(sum+arr[i]<=x) {
			sum+=arr[i],temp[groupCnt-1]++;
		} else {
			sum = arr[i],groupCnt++,temp[groupCnt-1]++;
		}
	}
	return (groupCnt<=M)?true:false;
}

int main() {
	cin>>N>>M;
	for(int i=0; i<N; i++) cin>>arr[i];

	int ans=0x7fffffff;
	ub=300*100;
	while(lb<ub) {
		m = (lb+ub-1)/2;
		if(promise(m)) {
			ub=m;
			copy(temp,temp+M,cnt);
			ans = min(ans,m);
		} else {
			lb=m+1;
		}
	}

	cout<<ans<<endl;
	for(int i=0; i<M; i++) {
		cout<<cnt[i]<<" ";
	}
	cout<<endl;

	return 0;
}

/*
8 3
5 4 2 6 9 3 8 7

*/