#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXLEN 1000

int m[MAXLEN][MAXLEN];
int dest[MAXLEN];
int a,b;
int solution[MAXLEN];

int init(int floor) {
	int i,cost=0;
	for(i=0; i<a; i++) {
		if(floor != dest[i]) {
			cost += abs(dest[i]-floor);
		}
	}
	return cost;
}
int f(int x, int y, int k) {
	int i,cost=0;
	for(i=0; i<a; i++) {
		if(x < dest[i] && dest[i]<=y) {
			cost += abs(dest[i]-k);
		}
	}
	return cost;
}
int calc(int i, int j, int k) {
	return (m[j][k] - f(k,dest[a-1],k) + f(k,i,i) + f(i,dest[a-1],i));
}

int main() {

	int i,j,k,cost_k,min_cost_k,cost_i,min_cost_i;
	int stop;

	while(1) {
		cout<<"���������Ϳ� ž���� ����� ���� ������������ �ִ� ���� Ƚ���� �Է��ϼ���."<<endl;
		cout<<"0 0 �Է½� ����"<<endl;
		cin>>a>>b;
		if(a==0 || b==0) break;
		cout<<"ž���� ������� ������ ������ �ϴ��� ��� �� ��ŭ �Է��ϼ���."<<endl;
		for(i=0; i<a; i++) cin>>dest[i];

		memset(m, 0, sizeof(m));
		memset(solution, 0, sizeof(solution));
		
		sort(dest, dest+a);
		min_cost_k=MAXLEN;
		for(i=0; i<=dest[a-1]; i++) {
			m[1][i] = init(i);
			if(m[1][i] < min_cost_k) {
				min_cost_k = m[1][i];
				stop = i;
			}
		}
		solution[1]=stop;

		for(j=2; j<=b; j++) {
			//min_cost_k=MAXLEN;
			for(i=j-1; i<=dest[a-1]; i++) {
				min_cost_k=MAXLEN;
				for(k=j-2; k<=i; k++) {
					cost_k = calc(i,j-1,k);
					if(cost_k < min_cost_k) {
						min_cost_k = cost_k;
						m[j][i] = cost_k;
						stop = k;
					}
				}
			}
			solution[j]=stop;
		}

		cout<<"�ּ� ��� : "<<min_cost_k<<endl<<endl;
	}

	return 0;
}
