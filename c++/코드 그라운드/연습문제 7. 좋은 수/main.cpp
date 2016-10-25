// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <string.h>
#include <algorithm>

int N,ans;
int A[5000];
int check[5000];

int search(int x, int sum) {
	int high, low, middle;
	low = x, high = N;

	while(low <= high) {
		middle = (low+high)/2;
		if(A[middle]==sum)
			return middle;
		if(A[middle] > sum) high=middle-1;
		else low = middle+1;
	}
	return -1;
}

void solve3(int x, int sum) {
	int middle = search(x, sum);
	if(middle!=-1 && check[middle]==0) {
		check[middle]=1, ans++;
	}
}


void solve2(int x, int sum) {
	for(int i=x; i<N; i++) {
		solve3(i, sum+A[i]);
	}
}

void solve1(int x, int sum) {
	for(int i=x; i<N; i++) {
		solve2(i, sum+A[i]);
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
        memset(A, 0, sizeof(A));
		memset(check, 0, sizeof(check));
		ans=0;

		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d", &A[i]);

		std::sort(A, A+N);
		for(int i=0; i<N; i++)
			solve1(i, A[i]);

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, ans);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}