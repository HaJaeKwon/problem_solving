// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <string.h>

int N,a[1000001],DT[1000001],K;
int ans;

void greedy(int x, int cost) {
	if(x==N) {
		ans=cost;
		return;
	}
	for(int i=N; i>=x+1; i--) {
		if(a[i] - a[x] <=K) {
			greedy(i,cost+1);
			break;
		}
	}
}

void solve(int x, int cost) {
	if(cost > ans || (DT[x]!=0 && DT[x]<=cost)) return;
	if(x==N) {
		if(cost < ans)
			ans = cost;
		return;
	}
	if(DT[x]==0) DT[x]=cost;
	else if(cost < DT[x]) {
		DT[x]=cost;
	}

	for(int i=x+1; i<=N; i++) {
		if(a[i] - a[x] <=K)
			solve(i,cost+1);
		else {
			break;
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
        
        scanf("%d", &N);
		for(int i=1; i<=N; i++)
			scanf("%d", &a[i]);
		scanf("%d", &K);

		memset(DT, 0, sizeof(DT));
		ans = 0x7fffffff;
		greedy(0,0);
		//solve(0,0);
        

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		if(ans != 0x7fffffff)
			printf("%d\n", ans);
		else
			printf("-1\n");
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}