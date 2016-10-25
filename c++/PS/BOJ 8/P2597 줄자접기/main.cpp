#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <deque>
#include <functional>
#include <sstream>
using namespace std;

// ������ ll �̻��� ��� INF�� 98765432100000 �������� ũ�� �ؾ���
// �Է¹޴� ���� 10^9 �̰� ���� ���� �װ͵��� ���ϴ� �����̶�� ���� ll �ϼ� �ִ�
// priority_queue �� �⺻������ �������� �����̴�. ������������ �ϰ� �ʹٸ� priority_queue<int, vector<int>, greater<int>>
// queue���� pop�ϱ� ������ �ݵ�� empty�� ��츦 üũ�ϰ� ����ó�� �����


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int N;
int red1, red2;
int blue1, blue2;
int yellow1, yellow2;

double convertCord(double x1, double x2) {
	return abs(x1 - x2);
}

int main() {

	scanf("%d", &N);
	
	scanf("%d%d", &red1, &red2);
	scanf("%d%d", &blue1, &blue2);
	scanf("%d%d", &yellow1, &yellow2);

	double point, length;
	int start = 0;
	int end = N;



	double r1, r2, b1, b2, y1, y2;
	
	point = ((double)red1 + red2) / 2;
	length = max(N - point, point);

	b1 = convertCord(point, blue1);
	b2 = convertCord(point, blue2);

	y1 = convertCord(point, yellow1);
	y2 = convertCord(point, yellow2);

	if (b1 != b2) {
		point = (b1 + b2) / 2;
		length = max(length - point, point);

		y1 = convertCord(point, yellow1);
		y2 = convertCord(point, yellow2);
	}

	if (y1 != y2) {
		point = (y1 + y2) / 2;
		length = max(length - point, point);
	}

	printf("%.1f\n", length);

	return 0;
}