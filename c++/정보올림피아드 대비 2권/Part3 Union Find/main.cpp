#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int un[100];
int n;

/*
6 4
3 2
1 3
5 4
3 5
*/

int union_find(int x) {
	vector<int> q;

	//���� ��ȣ�� ���� ���Ұ� �ƴ� ���� ���� ������ ã�ư���.
	while(un[x] != x) {
		if(un[x] != un[un[x]]) q.push_back(x);
		x = un[x];
	}

	while(!q.empty()) {
		un[q.back()] = x;
		q.pop_back();
	}

	return x;
}

int main() {

	int m,i,a,b,p,q,uc;
	bool prn[100];
	cin>>n>>m;
	// ó������ ���հ����� ������ ������ ����.
	uc=n;
	// ���� ó������ ������ ���Ҹ� �ϳ��� ���� �������� �����Ѵ�.
	for(i=1; i<=n; i++) un[i]=i;

	while(m--) {
		cin>>a>>b;
		p = union_find(a);
		q = union_find(b);
		if(p != q) {
			if(p<q) un[q]=p;
			else un[p]=q;
			uc--;
		}
	}
	cout<<uc<<endl;

	return 0;
}