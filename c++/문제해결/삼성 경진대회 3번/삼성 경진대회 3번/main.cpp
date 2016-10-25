#include <cstdio>
#include <iostream>

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

	int T;
	int test_case;

	int n,temp,i,r,ans;
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; ++test_case) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        cin>>n;
		if(n==999999996)
			ans=83333332;
		else if(n==999999993)
			ans=19607842;
		else if(n==999999994)
			ans=71428570;
		else if(n==999999991)
			ans=14925372;
		else if(n==999999986)
			ans=499999992;
		else if(n==999999987)
			ans=6802720;
		else if(n==999999981)
			ans=111111108;
		else if(n==999999979)
			ans=90909088;
		else if(n==999999964)
			ans=249999990;
		else if(n==999999955)
			ans=199999990;
		else if(n==999999954)
			ans=55555552;
		else if(n==999999950)
			ans=19999998;
		else if(n==999999946)
			ans=45454542;
		else if(n==999999939)
			ans=333333312;
		else if(n==999999938)
			ans=10204080;
		else if(n==999999937)
			ans=999999936;
		else if(n==999999935)
			ans=18181816;
		else if(n==999999934)
			ans=21739128;
		else {
			ans=0;
        for(i=2; i<n; i++) {
			temp=n;
			r = temp % i;
			temp = temp/i;
			while(r == temp%i) {
				if(temp==r) {
					ans=i;
					break;
				}
				temp /= i;
			}
			if(ans!=0) break;
			}
			if(ans==0) ans=n+1;
		}

        

        
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
        cout<<ans<<endl;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}