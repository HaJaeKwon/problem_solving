// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define INF 9999999

int N,M,map[1001][1001],check[1001];

int MAX(int a, int b) {
	if(a>b) return a;
	return b;
}
int MIN(int a, int b) {
	if(a<b) return a;
	return b;
}

void solve(int x) {

	int value[1001];
	int f[1001];
	int index[1001];

	memset(index, 0, sizeof(index));
	
	for(int i=1; i<=N; i++) {
		value[i]=INF;
		f[i]=0;
	}
	value[x]=0;

	for(int i=1; i<=N; i++) {
		int min=INF, p;
		for(int j=1; j<=N; j++) {
			if(f[j]==0 && value[j]<min) {
				p=j;
				min = value[j];
			}
		}
		f[p]=1;
		for(int j=1; j<=N; j++) {
			if(value[p]+map[p][j] < value[j]) {
				value[j] = value[p]+map[p][j];
				index[j]=p;
			}
		}
	}
	for(int i=1; i<=N; i++) {
		if(index[i]!=0) {
			int j = index[i];
			while(j!=0) {
				if(index[j]!=0)
					check[j]=1;
				j=index[j];
			}
		}
	}
}

int main(void) {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        int a,b,c;
		memset(check,0,sizeof(check));

        scanf("%d %d", &N, &M);
		
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				map[i][j]=INF;
		for(int i=1; i<=M; i++) {
			scanf("%d %d %d", &a, &b, &c);
			map[a][b]=c;
			map[b][a]=c;
		}

		for(int i=1; i<=N; i++)
			solve(i);

		std::vector<int> list;
		for(int i=1; i<=N; i++)
			if(check[i]==0) list.push_back(i);
		std::sort(list.begin(), list.end());

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		if(list.size()==0) {
			printf("0\n");
		} else {
			printf("%d ", list.size());
			for(int i=0; i<list.size(); i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		}
		
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}