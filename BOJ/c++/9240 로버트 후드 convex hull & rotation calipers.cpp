#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef pair<int,int> intPair;
typedef tuple<double,int,int> Point;

//���� ������ �Ÿ�
double dist(const Point &A, const Point &B) {
	return sqrt(pow(get<1>(A)-get<1>(B),2.0)+pow(get<2>(A)-get<2>(B),2.0));
}
//�������� �Ÿ�
double dist(const intPair &P) {
	return sqrt(pow(P.first,2.0)+pow(P.second,2.0));
}
// �Ÿ��� ���� ������ ��
int square(const Point &A, const Point &B) {
	return (get<1>(A)-get<1>(B))*(get<1>(A)-get<1>(B)) + (get<2>(A)-get<2>(B))*(get<2>(A)-get<2>(B));
}
// �� ���� ������ ����� ���� ũ��
double angle(const intPair &P, const intPair &Q) {
	return acos((P.first*Q.first + P.second*Q.second)/dist(P)/dist(Q));
}
double ccw(const Point &A, const Point &B, const Point &C) {
	return (get<1>(B)-get<1>(A))*(get<2>(C)-get<2>(A))-(get<2>(B)-get<2>(A))*(get<1>(C)-get<1>(A));
}
// �� ���� ����, x��ǥ, y��ǥ ������ ���ϴ� �Լ�
bool compare(const Point &A, const Point &B) {
	if(get<0>(A) != get<0>(B)) return get<0>(A) > get<0>(B);
	if(get<2>(A) == get<2>(B)) return get<1>(A) < get<1>(B);
	return get<2>(A) > get<2>(B);
}

const intPair operator -(const intPair &P) {
	return intPair(-P.first,-P.second);
}
const intPair operator -(const Point &P, const Point &Q) {
	return intPair(get<1>(P)-get<1>(Q),get<2>(P)-get<2>(Q));
}
int main() {
	int N;
	scanf("%d", &N);
	vector<Point> p(N);
	for(int i=0; i<N; i++) {
		int x,y;
		scanf("%d %d", &x, &y);
		p[i]=Point(0,x,y);
	}
	// x��ǥ�� ���� ���� ���� ã�� pivot���� ���
	sort(p.begin(),p.end(),compare);

	for(int i=1; i<N; i++) {
		get<0>(p[i])=(get<1>(p[i])-get<1>(p[0]))/dist(p[0],p[i]);
	}
	sort(p.begin()+1,p.end(),compare);

	vector<Point> hull;
	hull.push_back(p[0]);
	hull.push_back(p[1]);
	int P=0,Q=1,next=2;
	int minY = get<2>(hull[1]);
	while(next<N) {
		while(hull.size() >=2) {
			Point first, second;
			first=hull.back();
			second=hull[hull.size()-2];
			if(ccw(second,first,p[next]) <0) break;
			hull.pop_back();
		}
		if(get<2>(p[next]) < minY ||
			get<2>(p[next])==minY && get<1>(p[next]) > get<1>(p[Q])) {
				minY = get<2>(p[next]);
				Q = hull.size()-1;
		}
		hull.push_back(p[next++]);
	}
	// ȸ���ϴ� Ķ���۽��� ���� �� �Ÿ� ã��
	int hSize = hull.size();
	int maxSquare = square(hull[P],hull[Q]);
	intPair Pv(-1,0);
	for(int i=0; i<hSize; i++) {
		double Pa,Qa;
		Pa = angle(Pv, hull[(P+hSize-1)%hSize]-hull[P]);
		Qa = angle(-Pv, hull[(Q+hSize-1)%hSize]-hull[Q]);
		if(Pa <= Qa) {
			Pv = hull[(P+hSize-1)%hSize]-hull[P];
			P = (P+hSize-1)%hSize;
		} else {
			Pv = hull[Q]-hull[(Q+hSize-1)%hSize];
			Q = (Q-hSize-1)%hSize;
		}
		maxSquare = max(maxSquare, square(hull[P],hull[Q]));
	}
	double ans = sqrt((double)maxSquare);
	//printf("%f\n",sqrt((double)maxSquare));
	cout.setf(ios::fixed);
	cout.precision(8);
	cout<<ans<<endl;
	return 0;
}

