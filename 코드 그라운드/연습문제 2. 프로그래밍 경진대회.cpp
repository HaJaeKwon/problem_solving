// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int N, score[300000], ans;

void solve(int x) {
	int scoreN = 1;
	int bound = score[x]+N;
	for(int i=N-1; i>x; i--) {
		int temp = score[i]+scoreN;
		scoreN++;
		if(temp <= bound) ans++;
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
        memset(score,0,sizeof(score));
		ans=0;
		
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &score[i]);
		/*
		std::sort(score, score+N);

		for(int i=0; i<N; i++) {
			solve(i);
		}
		*/

		std::sort(score, score + N);
		int high = 0;
		int ans = 0;
		for (int i=N-1, n=1; i>=0; i--, n++) {
			high = std::max(high, score[i] + n);
		}
		for (int i=N-1, n=1; i>=0; i--, n++) {
			int a = score[i] + N >= high;
			ans += a;
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, ans);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}