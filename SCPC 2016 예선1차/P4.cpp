#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

#define INF 987654321
#define MAXN 100010

int N,M,K;
vector<int> sellter;
vector<pair<int, int> > v[MAXN];
priority_queue<pair<int,int> > pq;

int sumDist[MAXN],sumIndex[MAXN];

void DST(int start) {
	int dis[MAXN];
	for(int i=0; i<MAXN; i++) dis[i]=INF;

	dis[start]=0;
	pq.push(make_pair(0,start));

	while(!pq.empty()) {
		pair<int,int> value = pq.top();
		pq.pop();

		int current = value.second;
		int cost = -value.first;

		//���� ���������� �Ÿ��� �� ª�� ��� ����
		if(dis[current] < cost) continue;

		for(int i=0; i<v[current].size(); i++) {
			int next = v[current][i].second;
			int nextCost = v[current][i].first + dis[current];

			if(dis[next] > nextCost) {
				dis[next] = nextCost;
				pq.push(make_pair(-nextCost,next));
			}
		}
	}
	for(int i=1; i<=N; i++) {
		if(start==i) continue;
		if(sumDist[i]==0) {
			sumDist[i]=dis[i];
			sumIndex[i]=start;
		} else {
			if(sumDist[i] > dis[i]) {
				sumDist[i]=dis[i];
				sumIndex[i]=start;
			}
		}
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
        
		int src,dest,cost,i;
		scanf("%d %d %d", &N, &M, &K);

		memset(sumDist,0,sizeof(sumDist));
		memset(sumIndex,0,sizeof(sumIndex));
		sellter.clear();
		for(int i=1; i<=N; i++) v[i].clear();

		for(i=1; i<=M; i++) {
			scanf("%d %d %d", &src, &dest, &cost);
			v[src].push_back(make_pair(cost,dest));
			v[dest].push_back(make_pair(cost,src));
		}
		for(i=0; i<K; i++) {
			scanf("%d", &src);
			sellter.push_back(src);
		}
        
		for(i=0; i<sellter.size(); i++) {
			DST(sellter[i]);
		}
		for(i=0; i<sellter.size(); i++) {
			sumIndex[sellter[i]]=sellter[i];
			sumDist[sellter[i]]=0;
		}

		long long sum1=0,sum2=0;
		for(int i=1; i<=N; i++) sum1+=sumDist[i], sum2+=sumIndex[i];
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%lld\n%lld\n", sum1, sum2);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}