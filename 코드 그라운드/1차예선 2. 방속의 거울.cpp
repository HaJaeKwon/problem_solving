// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <string.h>

int N, map[1000][1000];
int visit[1000][1000];

int f(int x, int y, int d, int cost) {
	if(x<0 || x>=N || y<0 || y>=N)
		return cost;
	if(visit[x][y]==0 && map[x][y]!=0) {
		visit[x][y]=1;
		cost++;
	}

	if(d==1) {
		if(map[x][y]==0) return f(x,y+1,d,cost);
		if(map[x][y]==1) return f(x-1,y,4,cost);
		if(map[x][y]==2) return f(x+1,y,2,cost);
	}
	if(d==2) {
		if(map[x][y]==0) return f(x+1,y,d,cost);
		if(map[x][y]==1) return f(x,y-1,3,cost);
		if(map[x][y]==2) return f(x,y+1,1,cost);
	}
	if(d==3) {
		if(map[x][y]==0) return f(x,y-1,d,cost);
		if(map[x][y]==1) return f(x+1,y,2,cost);
		if(map[x][y]==2) return f(x-1,y,4,cost);
	}
	if(d==4) {
		if(map[x][y]==0) return f(x-1,y,d,cost);
		if(map[x][y]==1) return f(x,y+1,1,cost);
		if(map[x][y]==2) return f(x,y-1,3,cost);
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
        scanf("%d", &N);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%1d", &map[i][j]);

		memset(visit, 0, sizeof(visit));
		int ans = f(0,0,1,0);
        

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}