#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAXN 10010

int V,E,counter,order[MAXN],isAP[MAXN];
std::vector<int> graph[MAXN];

int dfs(int s, bool isRoot) {
	
	order[s]=++counter;
	int ret = order[s];

	int child=0;
	for(int i=0; i<graph[s].size(); i++) {
		int next=graph[s][i];
		if(!order[next]) {
			child++;
			int low = dfs(next,false);
			// next���� ���� �ִ� ������ ������ ���� ���� ����
			// next�� �������� ũ�ٸ�, ��ȸ�ΰ� ���� ���̴�.
			// ��� �������� �ش�ȴ�.
			if(!isRoot && low >= order[s])
				isAP[s]=true;
			ret = std::min(ret,low);
		} else {
			ret = std::min(ret,order[next]);
		}
	}
	if(isRoot)
		isAP[s] = (child>=2);
	return ret;
}

int main() {

	scanf("%d %d", &V, &E);
	for(int i=0; i<E; i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i=1; i<=V; i++) {
		if(!order[i]) dfs(i,true);
	}

	int ans=0;
	for(int i=1; i<=V; i++) {
		if(isAP[i]) ans++;
	}
	printf("%d\n", ans);
	for(int i=1; i<=V; i++) {
		if(isAP[i]) printf("%d ", i);
	}

	return 0;
}