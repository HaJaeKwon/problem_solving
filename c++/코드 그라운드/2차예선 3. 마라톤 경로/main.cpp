#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

int M,N,K;
int high[101][101],bottle[101][101],map[101][101];
int bottleX[10201], bottleY[10201];
int bottle_cnt;

int abs(int a) {
	if(a>0) return a;
	return -a;
}
int promise(int x, int y, int water) {
	int count=0;
	for(int i=0; i<bottle_cnt; i++) {
		if(x <= bottleX[i] && y <= bottleY[i]) {
			count++;
			if(water + count >= K) {
				break;
			}
		}
	}
	if(water + count >= K) return TRUE;
	return FALSE;
}

void solve(int x, int y, int cost, int water) {
	if(x>N || y>M) return;
	//if(promise(x,y,water) == FALSE) return;
	if(water>=K && cost >= map[N][M]) return;
	if(x==N && y==M) {
		water += bottle[x][y];
		if(water>=K && cost<map[N][M]) {
			map[N][M]=cost;
		}
		return;
	}
	water += bottle[x][y];

	solve(x+1,y,cost+abs(high[x][y]-high[x+1][y]) ,water);
	solve(x,y+1,cost+abs(high[x][y]-high[x][y+1]) ,water);
	/*\
	
	if(water>=K && map[x][y] != 0 && map[x][y] > cost)
		map[x][y]=cost;
	else if(water>=K && map[x][y] == 0)
		map[x][y]=cost;

	if(water>=K && map[x+1][y] != 0 && map[x+1][y] > cost+abs(high[x][y]-high[x+1][y])) {
		solve(x+1,y,cost+abs(high[x][y]-high[x+1][y]) ,water);
	} else if(map[x+1][y] == 0)
		solve(x+1,y,cost+abs(high[x][y]-high[x+1][y]) ,water);

	if(water>=K && map[x][y+1] != 0 && map[x][y+1] > cost+abs(high[x][y]-high[x][y+1])) {
		solve(x,y+1,cost+abs(high[x][y]-high[x][y+1]) ,water);
	} else if(map[x][y+1] == 0)
		solve(x,y+1,cost+abs(high[x][y]-high[x][y+1]) ,water);
		*/
}

int main(void) {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	   printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   �ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T,t;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		
        scanf("%d %d %d", &M, &N, &K);
		
		memset(map, 0, sizeof(map));
		memset(bottleX, 0, sizeof(bottleX));
		memset(bottleY, 0, sizeof(bottleY));
		bottle_cnt = 0;;

		for(int i=0; i<=N; i++)
			for(int j=0; j<=M; j++) {
				scanf("%d", &t);
				if(t<0) {
					high[i][j]=-t;
					bottle[i][j]=1;
					bottleX[bottle_cnt]=i;
					bottleY[bottle_cnt++]=j;
				} else {
					high[i][j]=t;
					bottle[i][j]=0;
				}
			}
		map[N][M]=0x7fffffff;
		solve(0,0,0,0);

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", map[N][M]);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}