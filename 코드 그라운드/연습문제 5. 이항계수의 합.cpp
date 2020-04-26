// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#define p 1000000007

long long int DT[2000001];
int N,M;

void fac(int x) {
	if(x>2000000) return;
	DT[x]=DT[x-1]+x;
	fac(x+1);
}

void init() {
	DT[0]=1;
	DT[1]=1;
	DT[2]=3;
	DT[3]=6;
	fac(4);
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

	init();

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        
        scanf("%d %d", &N, &M);
		int i=N+1, j=M+1;
		long long int ans = ((DT[i+j]%p)/DT[i]*DT[j])%p;
        

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%lld\n", test_case, ans);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}