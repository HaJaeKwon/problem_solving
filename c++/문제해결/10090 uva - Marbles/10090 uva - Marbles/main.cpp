#include <iostream>

using namespace std;

int main() {
	long n,c1,c2,n1,n2,m1,m2;
	long temp;
	int check;


	while(1) {
		cin>>n;
		if(n==0) break;
		cin>>c1>>n1;
		cin>>c2>>n2;

		check=0;
		// �뷮 �� ���ݺ� �Ѱ��� c1,n1���� �д�
		if((double)c1/n1 > (double)c2/n2) {
			swap(c1,c2);
			swap(n1,n2);
			check=1;
		}
		// ������ �ִ������� ���� �� �ִ� ù��° ������ ����
		m1 = n/n1;
		// loop�� ������ �ִ������� ���� �� �ִ� õ��° ������ ��������
		// �ι�° ������ ũ�⸦ �� �� ��ŭ�� ���� �ȴ�.
		for(; m1>=n/n1-n2 && m1>=0; m1--) {
			// ù��° ������ ������ �ϳ��� �ٿ����鼭 �� ���ڿ� �ִ���
			// ��� ���� �������� �ι�° ���ڷ� ä���.
			m2 = (n-m1*n1)/n2;
			if(n == m1*n1 + m2*n2) break;	// �׷��� �ؼ� ���� ������ ������ break
		}
		if(n==m1*n1 + m2*n2) {
			if(check==0)
				cout<<m1<<" "<<m2<<endl;
			else
				cout<<m2<<" "<<m1<<endl;
		} else
			cout<<"failed"<<endl;
	}
	return 0;
}