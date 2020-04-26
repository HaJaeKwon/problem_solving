#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define INF 987654321

vector<int> v[110];
int K,L,N,M,minDegree;
int Degree[110];
bool alive[110];

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

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        scanf("%d %d", &K, &L);
		scanf("%d %d", &N, &M);
		
		int src,dest,answer=0;
		minDegree = INF;
		memset(alive,false,sizeof(alive));
		for(int i=0; i<=N; i++) v[i].clear();

		for(int i=0; i<M; i++) {
			scanf("%d %d", &src, &dest);
			v[src].push_back(dest);
			v[dest].push_back(src);
			minDegree = min(minDegree,(int)v[src].size());
			minDegree = min(minDegree,(int)v[dest].size());
		}
        

		for(int i=1; i<=N; i++) {
			int size1=0, size2=0;
			for(int j=0; j<v[i].size(); j++) {
				if(alive[v[i][j]]==false) size1++;
			}
			if(N-size1-1 < L) {
				answer += i;
				continue;
			}
			int d=INF;
			for(int j=0; j<v[i].size(); j++) {
				size2=0;
				for(int k=0; k<v[v[i][j]].size(); k++) {
					if(alive[v[v[i][j]][k]]==false) size2++;
				}
				d=min(d,size2-1);
			}
			if(d>K) {
				answer += i;
				for(int j=0; j<v[i].size(); j++) {
					alive[v[i][j]]=true;
				}
			}
		}
        
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
        printf("%d\n", answer);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}