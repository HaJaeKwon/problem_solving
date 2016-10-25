#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 4010

string a,b,str;
int DP[MAXN][MAXN],p[MAXN][MAXN];
int cnt;

void LCS() {
	int i,j,l1,l2;
	l1=a.length();
	l2=b.length();

	int lastX,lastY;

	for(i=1; i<=l1; i++) {
		for(j=1; j<=l2; j++) {
			// �� ���ڰ� ���� ���
			if(a[i-1]==b[j-1]) {
				DP[i][j]=DP[i-1][j-1]+1;
				// ���� �밢�� ��� 1�� ����
				p[i][j]=1;
				lastX=i,lastY=j;
			}
			// ���� ���� ���
			else {
				// ���ʿ��� ���� ���� �� ���� ���
				if(DP[i][j-1]>=DP[i-1][j]) {
					DP[i][j]=DP[i][j-1];
					// ��ȭ��ǥ ��� 2�� ����
					p[i][j]=2;
				}
				// ������ ���� ���� �� ���� ���
				else {
					DP[i][j]=DP[i-1][j];
					// �Ʒ�ȭ��ǥ ��� 3���� ����
					p[i][j]=3;
				}
			}
		}
	}
	//���� ���� ���ڿ� ������
	i=l1;
	j=l2;
	while(i>0 && j>0) {
		switch(p[i][j]) {
		case 1:
			// �밢������ �ö󰡴� ���
			// �ش� ���� ���ڿ� ����
			str[cnt++]=a[i-1];
			i--,j--;
			break;
		case 2:
			// �������� ���� ���
			j--;
			break;
		case 3:
			i--;
			break;
		}
	}
	// �Ųٷ� ����� ���� ���ڿ� ���
	for(i=cnt-1; i>=0; i--) {
		cout<<str[i];
	}
	cout<<endl;

	printf("%d\n", DP[lastX][lastY]);
}

int main() {
	cin>>a>>b;

	LCS();

	return 0;
}