#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct vertex {
	int weight,idx;
};

int rn[100][100];
int maxFlow,n;
bool check[100];
vector<int> path;

int vertex_sort(const vertex& a, const vertex& b) {
	return a.weight>b.weight;
}

bool PFS(int x, int localFlow) {
	int i;
	vector<vertex> v;
	vertex vx;

	if(x==n-1) {
		// DFS�� ���� �����ϸ� �Դ� ��ε鿡�� flow�� ������Ʈ ����� �Ѵ�.
		// MaxFlow�� ���� ����� �ּ� flow�� �����ش�.
		maxFlow += localFlow;
		// RN�� �����Ѵ�.
		for(i=0; i<path.size()-1; i++) {
			rn[path[i]][path[i+1]] -= localFlow;
			rn[path[i+1]][path[i]] += localFlow;
		}
		path.clear();
		path.push_back(0);
		return true;
	}
	// ���� �������� �����ִ� ���� ������ ������ ����
	for(i=0; i<n; i++) {
		if(rn[x][i] > 0 && check[i]==false) {
			vx.idx = i;
			vx.weight = rn[x][i];
			v.push_back(vx);
		}
	}
	// priority�� ���� weight�� ���� ����
	sort(v.begin(), v.end(), vertex_sort);

	for(i=0; i<v.size(); i++) {
		// ���� �������� ���õ� ���� �湮���� �ʵ��� üũ
		check[v[i].idx] = true;
		// ��ο� �� ������ �߰�
		path.push_back(v[i].idx);
		// �뷮�� ū �ͺ��� ���ʴ�� �湮�ȴ�.
		// �ϳ��� ��ΰ� ó���Ǹ� ������ �湮���� �ʰ� true �����ϸ� ����
		// ���������� ���� �뷮�� �ּҷ� �����ذ���.
		if(PFS(v[i].idx, min(localFlow, v[i].weight)) == true)
			return true;
		   
		// üũ�� ��ο� ���ؼ� ����
		path.pop_back();
		check[v[i].idx] = false;
	}
	return false;
}

void MaxFlow() {
	path.push_back(0);
	while(PFS(0,987654321)) {
		// �ϳ��� ��ΰ� ó���Ǹ� check�� ��� �ʱ�ȭ�ϰ� �ٽ� Ž��. ��ΰ� ���������� �ݺ�
		fill(check,check+n,false);
		check[0]=true;
	}
}

int main() {
	int m,a,b,c;
	cin>>n>>m;

	while(m--) {
		cin>>a>>b>>c;
		rn[a][b]=c;
	}
	MaxFlow();

	cout<<maxFlow<<endl;

	return 0;
}

/*
6 10
0 1 14
0 3 18
1 2 15
1 3 12
2 4 9
2 5 6
3 1 6
3 4 16
4 1 11
4 5 28
*/