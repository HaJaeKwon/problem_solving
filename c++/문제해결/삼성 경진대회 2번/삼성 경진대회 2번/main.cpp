#include <cstdio>
#include <iostream>
#include <string.h>

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

	int T,i,j,count,N;
	int test_case;

	int **map;
	map = new int*[1000];
	for(i=0; i<1000; i++) map[i]=new int[1000];
	
	int **checked;
	checked = new int*[1000];
	for(i=0; i<1000; i++) checked[i]=new int[1000];

	char input[1001];

	int Dx1[4] = {0, -1, 0, 1};
	int Dy1[4] = {-1, 0, 1, 0};
	int Dx2[4] = {0, 1, 0, -1};
	int Dy2[4] = {1, 0, -1, 0};

	int x,y,d;
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; ++test_case) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        
        cin>>N;
		for(i=0; i<N; i++) {
			cin>>input;
			for(j=0; j<N; j++) {
				map[j][i] = input[j]-'0';
				checked[j][i]=0;
			}
		}
		x=0,y=0,d=0,count=0;
		while(x>=0 && x<N && y>=0 && y<N) {
			switch (map[x][y]) {
			case 1:
				if(!checked[x][y]) {
					count++;
					checked[x][y]=1;
				}
				x = x+Dx1[d];
				y = y+Dy1[d];
				switch(d) {
				case 0:
					d=3;
					break;
				case 1:
					d=2;
					break;
				case 2:
					d=1;
					break;
				case 3:
					d=0;
					break;
				}
				break;
			case 2:
				if(!checked[x][y]) {
					count++;
					checked[x][y]=1;
				}
				x = x+Dx2[d];
				y = y+Dy2[d];
				switch(d) {
				case 0:
					d=1;
					break;
				case 1:
					d=0;
					break;
				case 2:
					d=3;
					break;
				case 3:
					d=2;
					break;
				}
				break;
			case 0:
				int goX, goY;
				switch(d) {
				case 0:
					goX=1, goY=0;
					break;
				case 1:
					goX=0, goY=1;
					break;
				case 2:
					goX=-1, goY=0;
					break;
				case 3:
					goX=0, goY=-1;
					break;
				}
				x = x+goX;
				y = y+goY;
				break;
			}
		}
        
        
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
        cout<<count<<endl;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}