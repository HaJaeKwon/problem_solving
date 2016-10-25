#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

#define isOdd(x) x%2 != 0 ? (true) : (false)
#define M 100000

long long dp[M];
long long answerMin[65],answerMax[65];

long long recursive(int count, long long number) {
	
	if(isOdd(number)) number = 3*number+1;
	else number /= 2;

	if(number < M && dp[number]!=-1) {
			return dp[number]+1;
		} else if(number < M){
			dp[number] = recursive(count, number);
			return dp[number]+1;
		} else {
			count = recursive(count, number);
			return count+1;
		}
}

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

	memset(dp, -1, M*sizeof(int));
	memset(answerMin, 0, sizeof(answerMin));
	int count;
	answerMin[0]=1,dp[1]=0;
	for(long long i=1; i<M; i++) {
		
		if(dp[i]!=-1) count=dp[i];
		else count=recursive(0,i);
		if(count>63) continue;

		answerMax[count] = max(answerMax[count],i);
		if(answerMin[count]==0) {
			answerMin[count] = i;
		} else {
			answerMin[count] = min(answerMin[count],i);
		}
	}
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        
        int K;
		long long S,L;
		scanf("%d",&K);
		
		unsigned long long int aaa = (unsigned long long int)pow(2.0,K);
		
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		//printf("Case #%d\n", test_case);
		cout<<"Case #"<<test_case<<endl;
		cout<<answerMin[K]<<" "<<aaa<<endl;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}