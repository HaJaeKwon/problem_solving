// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 55555555
			
int N;
int mem[MAX];

int f(int x, int b, int num) {
	if(num==0) return 0;
	if(x==0) return b;
	
	/*
	if(num==t)
		return f(x/b,b,t);
	return -1;
	*/

	if(x<MAX) mem[x]=mem[x/b];
	if(x/b<MAX && mem[x/b]!=0 && mem[x/b]==num) {
		return mem[x/b];
	} else {
		int t = x%b;
		if(num==t) {
			int ans = f(x/b,b,t);
			if(ans==-1) {
				if(x<MAX) mem[x]=0;
				return -1;
			}
		} else {
			if(x<MAX) mem[x]=0;
			return 0;
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
        
		//memset(mem,0,sizeof(mem));

        scanf("%d", &N);

		double start = clock();
	


		int i,ans;
		if(N==1) ans=2;
		for(i=2; i<N; i++) {
			if(N/i<MAX && mem[N/i]!=0 && mem[N/i]==N%i) {
				
				ans = mem[N/i];
				break;
			} else {
				ans = f(N/i,i,N%i);
			}
			if(ans!=0) {
				if(N<MAX) mem[N]=ans;
				break;
			}
		}
		if(i==N)
			ans = N+1;
        

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, ans);
        printf("\nresult=%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}