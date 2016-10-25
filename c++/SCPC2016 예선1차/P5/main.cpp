#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct vertex {
	int weight,idx;
};

int rn[500][500];
int maxFlow,n;
bool check[500];
vector<int> path;

int N,K,a[210],f[210],p[210],s[110],e[110];

int vertex_sort(const vertex& a, const vertex& b) {
	return a.weight>b.weight;
}

bool PFS(int x, int localFlow) {
	int i;
	vector<vertex> v;
	vertex vx;

	if(x==1) {
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

	int T;
	int test_case;
    
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        
		int timeTable[200],maxTime=0;
		memset(timeTable,0,sizeof(timeTable));
		bool check=true;

		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++) {
			scanf("%d %d %d",&a[i],&f[i],&p[i]);
			for(int j=a[i]; j<f[i]; j++) {
				timeTable[j]--;
			}
			if(f[i]-a[i] != p[i]) {
				check=false;
			}
		}
		for(int i=0; i<K; i++) {
			scanf("%d %d",&s[i],&e[i]);
			for(int j=s[i]; j<e[i]; j++) {
				timeTable[j]++;
			}
			maxTime = max(maxTime,e[i]);
		}
		bool answerCHK=true;
		for(int i=0; i<maxTime; i++) {
			if(timeTable[i] <0) answerCHK=false;
		}
		printf("Case #%d\n", test_case);
		if(check==true) {
			if(answerCHK==true) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		} else {
			memset(rn,0,sizeof(rn));
			n=0,maxFlow=0;
			int answer=0;

			for(int i=0; i<N; i++) {
				rn[0][i+2]=p[i];
				for(int j=a[i]; j<f[i]; j++) {
					rn[i+2][N+j+2]=1;
				}
				answer+=p[i];
			}
			for(int i=0; i<K; i++) {
				for(int j=s[i]; j<e[i]; j++) {
					rn[N+j+2][1]++;
				}
				n=max(n,e[i]);
			}
			n = 2+N+n+1;
			MaxFlow();
			bool chk=true;
			for(int i=0; i<N; i++) {
				if(rn[0][i+2]!=0) chk=false;
			}
			// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
			if(chk==true) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}