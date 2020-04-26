// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <cmath>

#define PI 3.1415926535

int A,B,C,D,E,N, ans;
int X[10000], Y[10000];
int pointPlus[20] = {6, 13, 13, 4, 4, 18, 18, 1, 1, 20, 20, 5, 5, 12, 12, 9, 9, 14, 14, 11};
int pointMinus[20] = {6, 10, 10, 15, 15, 2, 2, 17, 17, 3, 3, 19, 19, 7, 7, 16, 16, 8, 8, 11};
int point[20] = {6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10};

double DDDD(int x, int y) {
	double arctanV = (atan2((double)y, (double)x) / PI) * 180.0; // arctan Value ���
	if(arctanV >= -9.0 && arctanV < 9.0) return 6;
	else if(arctanV >= 9.0 && arctanV < 27.0) return 13;
	else if(arctanV >= 27.0 && arctanV < 45.0) return 4;
	else if(arctanV >= 45.0 && arctanV < 63.0) return 18;
	else if(arctanV >= 63.0 && arctanV < 81.0) return 1;
	else if(arctanV >= 81.0 && arctanV < 99.0) return 20;
	else if(arctanV >= 99.0 && arctanV < 117.0) return 5;
	else if(arctanV >= 117.0 && arctanV < 135.0) return 12;
	else if(arctanV >= 135.0 && arctanV < 153.0) return 9;
	else if(arctanV >= 153.0 && arctanV < 171.0) return 14;
	else if(arctanV >= 171.0 || arctanV < -171.0) return 11; // OR ����(��谪)�ӿ� ����
	else if(arctanV >= -171.0 && arctanV < -153.0) return 8;
	else if(arctanV >= -153.0 && arctanV < -135.0) return 16;
	else if(arctanV >= -135.0 && arctanV < -117.0) return 7;
	else if(arctanV >= -117.0 && arctanV < -99.0) return 19;
	else if(arctanV >= -99.0 && arctanV < -81.0) return 3;
	else if(arctanV >= -81.0 && arctanV < -63.0) return 17;
	else if(arctanV >= -63.0 && arctanV < -45.0) return 2;
	else if(arctanV >= -45.0 && arctanV < -27.0) return 15;
	else if(arctanV >= -27.0 && arctanV < -9.0) return 10;
	else return 0;
}

double getDistance(int x, int y) {
	return sqrt((double)x*x + (double)y*y);
}
double getDegree(int x, int y) {
	return (atan2((double)y,(double)x))*180/PI;
}

int getScore(int x, int y) {

	double R = getDistance(x, y);
	int score;
	if(R < A) return 50;
	else if( R < B) score = 1;
	else if( R < C) score = 3;
	else if( R < D) score = 1;
	else if( R < E) score = 2;
	else return 0;

	//return score * DDDD(x,y);

	/*
	double degree = getDegree(x, y);
	if(degree >= 0) {
		degree = (degree)/9;
		return score * pointPlus[(int)degree];
	} else {
		degree *= -1;
		degree = (degree)/9;
		return score * pointMinus[(int)degree];
	}
	*/
	double degree = getDegree(x, y)+9;
	if(degree<0)
		degree+=360;
	return score*point[(int)degree/18];
}

int main(void) {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        ans=0;
        scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d %d", &X[i], &Y[i]);
			ans += getScore(X[i], Y[i]);
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, ans);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}