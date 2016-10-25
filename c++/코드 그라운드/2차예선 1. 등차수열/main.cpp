#include <stdio.h>

long gcd(long a, long b) {
	long x,y,r;
	if(a > b) x =a, y= b;
	else x = b, y =a;

	r = x%y;
	if(r==0) return y;
	else gcd(y,r);
}

long divisor(long x) {
	long temp=0;
	long i;
	for(i=1; i*i<x; i++) {
		if(x%i==0) {
			temp+=2;
		}
	}
	if(i*i==x) {
		temp++;
	}
	
	return temp;
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

	int T;
	int test_case;

	int M, check_zero;
	long a,b, d1, d2,ans;

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        check_zero=0;
		scanf("%d", &M);
		scanf("%ld", &a);
		for(int i=1; i<M; i++) {
			scanf("%ld", &b);
			if(i==1) {
				d1 = b-a;
				a = b;
			} else {
				d2 = b-a;
				if(check_zero == 0 && d2 != 0 && d1 != 0) {
					d1 = gcd(d1,d2);
				} else {
					if(check_zero == 0 && d1!=d2 ) {
						ans=0;
					} else if(check_zero == 0) {
						ans=1;
					}
					if (check_zero==1 && d1 != d2) {
						ans=0;
					}
					check_zero = 1;
				}
			}
		}
		if(!check_zero) {
			ans = divisor(d1);
		}
		printf("Case #%d\n", test_case);
		printf("%ld\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}