// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>

int N,ans;


void solve() {
	ans = N+1;

	int a,b,k;
		for(a=1; a*a<N; a++) {
		if(N%a==0) {
			k = N/a;
			k = k -1;
			for(b=1; b*b<k; b++) {
				if(k%b==0) {
					if(b>a) {
						int temp = k;
						while(temp%b==0 && temp>0) {
							temp = temp/b-1;
						}
						if(temp==0) {
							if(b < ans) ans = b;
							return;
						}
					}
					if(k/b > a) {
						int x = k / b, temp = k;
						while(temp % x == 0 && temp > 0) temp = (temp/x - 1);
						if(temp == 0) {
							if(x < ans)
								ans =x;
						}
					}
				}
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

        scanf("%d", &N);

		solve();
        

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}