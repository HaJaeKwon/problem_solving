#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

#define p 1000000009
#define p2 2000000018

int N,K,L;
long long DP[51000][110];
bool mine[50010];

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	   C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   ���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T,t;
	int test_case;
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        
		memset(DP,0,sizeof(DP));
		memset(mine,false,sizeof(mine));

        scanf("%d %d %d",&N, &K, &L);
		if(L!=0) {
			for(int i=0; i<L; i++) {
				scanf("%d",&t);
				mine[t]=true;
			}
		}
		
		
		for(int i=1; i<=K; i++) {
			if(mine[i]==true) continue;
			DP[i][i]=1;
		}
		for(int i=1; i<=N; i++) {
			if(mine[i]==true) continue;
			for(int j=1; j<=K; j++)  {
				if(i-j<0) continue;
				if(DP[i-j][0]-DP[i-j][j]<0) DP[i][j]+=p;
				DP[i][j] += (DP[i-j][0]-DP[i-j][j]);
				DP[i][j] %= p;
			}
			for(int k=1; k<=K; k++) {
				DP[i][0] += DP[i][k];
				DP[i][0] %= p;
			}
		}
		DP[N][0] %= p;
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);		
		printf("%lld\n", DP[N][0]);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}