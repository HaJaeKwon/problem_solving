#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int rn[100][100], total;
bool check[100];
vector<int> man, woman, path;
map<int,int> place,fn;

bool DFS(int x) {
	int i;
	// �������� �����ϸ�
	if(x==total) {
		// RN�� FN�� �����Ѵ�.
		for(i=0; i<path.size()-1; i++) {
			// ���ڱ׷��� ���ҿ��� ����ϴ� ������ �����Ѵ�.
			if(find(man.begin(), man.end(), path[i]) != man.end()) {
				fn[path[i]] = path[i+1];
			}
			rn[path[i]][path[i+1]] -= 1;
			rn[path[i+1]][path[i]] += 1;
		}
		path.clear();
		path.push_back(0);

		return true;
	}
	// ���� �������� �����ִ� ���� ������ ������ ����
	// ���� �̹� �湮�ߴ� ������ �����Ѵ�.
	for(i=1; i<=total; i++) {
		if(rn[x][i]==1 && check[i]==false) {
			check[i]=true;
			//��ο� �߰�
			path.push_back(i);

			// �ϳ��� ��ΰ� ó���Ǹ� ������ �湮���� �ʰ� true
			// �����ϸ� ����
			if(DFS(i)==true) return true;

			// üũ�� ��ο� ���ؼ� ����
			path.pop_back();
			check[i]=false;
		}
	}
	return false;
}

void BipariteMatching() {
	path.push_back(0);
	while(DFS(0)) {
		fill(check, check+total+1, false);
		check[0]=true;
	}
}

int main() {

	int n,a,b,i;
	cin>>n;
	man.reserve(n);
	while(n--) {
		cin>>a;
		// ���ڱ׷쿡 ���ϴ� ��ȣ�� 0���� �����Ѵ�.
		place[a]=0;
		// ���� �׷� ��ȣ�� ����
		man.push_back(a);
	}
	cin>>n;
	woman.reserve(n);
	while(n--) {
		cin>>a;
		// ���ڱ׷쿡 ���ϴ� ��ȣ�� 1�� �����Ѵ�.
		place[a]=1;
		// ���� �׷� ��ȣ�� ����
		woman.push_back(a);
	}
	cin>>n;
	while(n--) {
		cin>>a>>b;
		// a�� ���� �׷��� ���
		if(place[a]==0) rn[a][b]=1;
		// b�� ���� �׷��� ���
		else rn[b][a]=1;
	}

	// ���� ��ȣ 0���� ��� ���� �׷� ��ȣ�� ���� ��Ų��.
	for(i=0; i<man.size(); i++) rn[0][man[i]] = 1;

	// ���� �׷��� ��� ��ȣ���� ���������� ��� ���� ��Ų��.
	// �������� �� �׷��� ���� +1 �̴�.
	total = man.size() + woman.size() + 1;
	for(i=0; i<woman.size(); i++) rn[woman[i]][total]=1;

	BipariteMatching();

	sort(man.begin(), man.end());

	for(i=0; i<man.size(); i++) {
		// fn�� ���ڱ׷쿡�� �����ϰ� �ϳ��� ���� ����ǹǷ�
		// ����� ���� �ִ� ��� ���
		if(fn.find(man[i]) != fn.end()) {
			cout<<man[i]<<" : "<<fn[man[i]]<<endl;
		}
	}

	return 0;
}