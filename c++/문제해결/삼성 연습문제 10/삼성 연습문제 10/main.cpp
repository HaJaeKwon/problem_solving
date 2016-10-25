#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int map[100001];
int k[2001][2];

int main(int argc, char** argv) {
	int T;
    int test_case;
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� cin �� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	   ��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);
	int N,M,K,i,j,x;
	scanf("%d", &T);	//Codeground �ý��ۿ����� C++ ������ scanf ����� �����մϴ�.
    for(test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
        //memset(map, 0, 100001*sizeof(int));
		
		cin>>N>>M>>K;
		for(i=1; i<=K; i++) cin>>k[i][0]>>k[i][1];
        
		for(i=1; i<=M; i++) map[i]=1;
		for(x=1; x<=K; x++) if(k[x][0]==1) map[k[x][1]]=0;
		for(i=2; i<=N; i++) {
			for(x=1; x<=K; x++) if(k[x][0]==i) map[k[x][1]]=-1;
			for(j=2; j<=M; j++) {
				if(map[j]==-1) {
					map[j]++;
					continue;
				}
				map[j] += map[j-1];
			}
		}

        
        
		//	�� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++ ������ printf ����� �����մϴ�. 
        printf("Case #%d\n", test_case);
        cout<<map[M]%1000000007<<endl;
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}