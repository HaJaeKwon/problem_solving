#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10001

int value[1001];
int f[1001];
int index[1001];

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

	int T,i,j,N,M,a,b,c,min,p,x;
	int test_case;

	int **map;
	map = new int*[1001];
	for(i=0; i<1001; i++) map[i]=new int[1001];

	int count, number;

	bool checked[1001];
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; ++test_case) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		cin>>N>>M;
		number=N;
		
		for(i=1; i<=N; i++) {
			checked[i]=false;
			for(j=1; j<=N; j++)
				map[i][j]=MAX;
		}
		for(i=1; i<=M; i++) {
			cin>>a>>b>>c;
			map[a][b]=c;
			map[b][a]=c;
		}
		for(x=1; x<=N; x++) {
			for(i=1; i<=N; i++) {
				value[i]=MAX;
				index[i]=0;
				f[i]=0;
			}
			value[x]=0;

			for(i=1; i<=N; i++) {
				min=MAX;
				for(j=1; j<=N; j++) {
					if((value[j]<min)&&f[j]==0) {
						min=value[j];
						p=j;
					}
				}
				if(checked[p]==true && p!=x) break;
				f[p]=1;
				for(j=1; j<=N; j++) {
					if(value[p]+map[p][j]<value[j]) {
						value[j]=value[p]+map[p][j];
						index[j]=p;
						if(p!=x && checked[p]==false) {
							checked[p]=true;
							number--;
						}
					}
				}

			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		cout<<number;
		if(number!=0) {
			for(i=1; i<=N; i++)
				if(checked[i]==false)
					cout<<" "<<i;
			cout<<endl;
		}
		
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}