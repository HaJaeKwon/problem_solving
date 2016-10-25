#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

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

	int T,M,i,j,count,flag_0;
	unsigned long long int b1,b2,d,min_number,result;
	int test_case;
	unsigned long long int c[100000];
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		d=0,flag_0=0;
		count=0;
        cin>>M>>b1;
		for(i=0; i<M-1; i++) {
			cin>>b2;
			if(b2-b1==0) flag_0++;
			c[i]=b2-b1;
			b1=b2;
		}
		if(flag_0>0 && flag_0!=M-1) {
			d=0;
		} else {
			sort(c,c+M-1);
			min_number = c[0];
			result=1;
			for(i=2; i<=min_number; i+=2) {
				count=0;
				for(j=0; j<M-1; j++) {
					if(c[j]%i==0) count++;
				}
				if(count==M-1) {
					for(j=0; j<M-1; j++) c[j]/=i;
					min_number/=i;
					result*=i;
					if(i==2) {
						i=0;
						continue;
					} else {
						i=1;
						continue;
					}
				}
			}
			for(i=1; i<=result; i++)
				if(result%i==0) d++;
		}
			
        
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
        printf("Case #%d\n", test_case);
		cout<<d<<endl;
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}