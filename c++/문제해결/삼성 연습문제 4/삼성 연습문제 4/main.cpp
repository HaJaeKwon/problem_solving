#include <cstdio>
#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int pt_n[21] = {0, 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8,16,7,19,3,17,2,15,10};
double upper[21] = {0, 9, 27, 45, 63, 81, 99, 117, 135, 153, 171, -171, -153, -135, -117, -99, -81, -63, -45, -27, -9};
double lower[21] = {0, -9, 9, 27, 45, 63, 81, 99, 117, 135, 153, 171, -171, -153, -135, -117, -99, -81, -63, -45, -27};
int bull, t_st, t_end, d_st, d_end;

double GetDegree(int x, int y) {
	return -(atan2(-(double)y,(double)x)*180/3.1415926535);
}
double GetDistance(int x, int y) {
	if(x==0) return abs(y);
	else if(y==0) return abs(x);

	return sqrt((double)x*x + y*y);
}
int GetPoint(int x, int y) {
	int t=1, count=0, result=1;

	double dis = GetDistance(x,y);

	if(dis<=bull) result = 50;
	else if(dis<=t_end && dis>=t_st) result = 3;
	else if(dis<=d_end && dis>=d_st) result = 2;
	else if (dis>=d_end) result = 0;

	if(result != 50 && result != 0) {
		double degree = floor(GetDegree(x,y));
		if(degree >= 0) {
			t=11;
			while(1) {
				if(lower[t] <= degree) break;
				--t;
			}
		} else {
			t=11;
			while(1) {
				if(upper[t] >= degree) break;
				++t;
			}
		}
	result *= pt_n[t];
	}
	

	

	return result;
}

int main(int argc, char** argv) {
	int T;
    int test_case;
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� cin �� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	   ��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);
	int i,result;
	int darts;
	int dart[10000][2];
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		memset(dart, 0, 10000*2*sizeof(int));
        result=0;
		cin>>bull>>t_st>> t_end>> d_st >> d_end;
		cin>>darts;
		for(i=0; i<darts; i++) cin>>dart[i][0]>>dart[i][1];
        for(i=0; i<darts; i++) result+=GetPoint(dart[i][0], dart[i][1]);
		
		//	�� �κп��� ������ ����Ͻʽÿ�.  
		cout << "Case #" << test_case << endl;
        cout<<result<<endl;
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}