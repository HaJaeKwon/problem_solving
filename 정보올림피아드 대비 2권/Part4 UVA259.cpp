#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
using namespace std;

// �� �׷��� ���ø����̼�, �Ʒ��׷��� ��ǻ�ͷ� �������
// ���ø����̼ǿ��� ������ ����Ǵ� ������ rnu(up)
// �Ŀ��� ���ø����̼����� ����Ǵ� ������ rnb(bottom)
bool rnu[27][10], rnb[10][27], checku[27], checkb[10];
int total, ap[10], no[27];
vector<int> path;

bool DFS(int x, bool from_up) {
	int i;

	// �������� �����ϸ�
	if(x==0 && from_up==true) {
		// 1~26�� ���ø����̼� ��ȣ�̰�, 0���� �������� ��ȣ
		// RN�� FN�� ����
		for(int i=0; i<path.size()-1; i++) {
			// ���ø����̼ǿ��� ��ǻ�ͷ� ����Ǵ� ���� ����
			if(i%2==0) {
				// ����Ǵ� �Ŀ� ���ø����̼��� �����Ѵ�.
				ap[path[i+1]] = path[i];
				rnu[path[i]][path[i+1]] = false;
				rnb[path[i+1]][path[i]] = true;

				// �Ҵ��� ���ø����̼� ������ �ٿ��ش�.
				total--;
				no[path[i]]--;
			} else {
				// ��ǻ�Ϳ��� ���ø����̼����� ����Ǵ� ���� ����
				rnb[path[i]][path[i+1]] = false;
				rnu[path[i+1]][path[i]] = true;

				// �Ҵ��ؾ��� ���ø����̼��� ������ �÷��ش�.
				// ���������� �������� �˻��ؾ��Ѵ�.
				if(path[i+1]>0) {
					total++;
					no[path[i+1]]++;
				}
			}
		}
		// ��θ� �ʱ�ȭ �Ѵ�.
		path.clear();
		fill(checku,checku+27,false);
		fill(checkb,checkb+10,false);
		return true;
	}

	// ������� ���, ���Ѵ�� ������ �����̱� ������ ��� ������ �˻��Ѵ�.
	if(x==-1) {
		for(int i=1; i<27; i++) {
			// �Ҵ��� ���ø����̼��� �ִ� ���
			if(no[i]>0) {
				path.push_back(i);
				if(DFS(i,true)==true) return true;
				path.pop_back();
			}
		}
		return false;
	}
	// ������� �ƴ� ���
	// ���ø����̼ǿ��� ��ǻ�ͷ� ���� ���
	if(from_up==true) {
		// ��ǻ���� �����ŭ ó��
		for(i=0; i<10; i++) {
			if(rnu[x][i]==true && checkb[i]==false) {
				// ������������ ���õ� �� �湮���� �ʵ��� üũ
				checkb[i]=true;
				// ��ο� ���� �߰�
				path.push_back(i);
				// �ϳ��� ��ΰ� ó���Ǹ� ������ �湮���� �ʰ� true �����ϸ� ����
				if(DFS(i,false)==true) return true;

				// üũ�� ��ο� ���ؼ� ����
				path.pop_back();
				checkb[i]=false;
			}
		}
	} else {
		// ��ǻ�Ϳ��� ���ø����̼����� ���� ���
		for(i=1; i<=27; i++) {
			// �������� ���� �������� �湮�ϵ��� ó��
			if(i==27) i=0;
			if(rnb[x][i]==true && rnu[i]==false) {
				checku[i]=true;
				// ��ο� ���� �߰�
				path.push_back(i);
				// �ϳ��� ��ΰ� ó���Ǹ� true�����ϸ� ����
				if(DFS(i,true)==true) return true;
				// üũ�� ��ο� ���ؼ� ����
				path.push_back(i);
				checku[i]=false;
			}
			// ������ ���� ����
			if(i==0) i==27;
		}
	}
	return false;
}

void BipariteMatching() {
	// ��ΰ� �����ϴ� ���� ��� DFS ����
	while(DFS(-1,false));
}

int main() {

	int i,n,a;
	string str,tmp;

	while(!cin.eof()) {
		total=0;
		fill(checku, checku+27, false);
		fill(checkb, checkb+10, false);
		fill(ap,ap+10,-1);
		fill(no,no+27,0);
		for(i=0; i<27; i++) fill(rnu[i], rnu[i]+10,false);
		for(i=0; i<10; i++) fill(rnb[i], rnb[i]+10,false);

		while(1) {
			getline(cin, str);
			if(str.length()<3) break;
			istringstream is(str);

			is>>tmp;
			a = tmp[0]-'A'+1;
			if(tmp.length()==3) n = 10;
			else n=tmp[1]-'0';
			no[a]=n;

			total += n;

			// �޺κ� ó��
			is>>tmp;
			for(i=0; i<tmp.length(); i++) {
				rnu[a][tmp[i]-'0']=true;

				// ��ǻ�Ϳ��� ������ ���������� ���� ���� ǥ��
				// ���ø����̼��� 1~26���� ����ϹǷ� �������� 0������ ����Ѵ�.
				rnb[tmp[i]-'0'][0] = true;
			}
		}

		BipariteMatching();

		if(total>0) cout<<"!"<<endl;
		else {
			for(i=0; i<10; i++) {
				//������� ���� ��� '_'
				if(ap[i]==-1) cout<<"_";
				else cout<<char(ap[i]+'A'-1);
			}
			cout<<endl;
		}
	}

	return 0;
}