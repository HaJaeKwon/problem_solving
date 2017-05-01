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

pair<int, int> getScore(string str) {
	stringstream ss(str);

	int *s1 = new int[2];

	int i = 0;
	while (1) {
		string token;
		if (getline(ss, token, ':')) {
			s1[i] = stoi(token);
		}
		else {
			break;
		}
		i++;
	}
	return mp(s1[0], s1[1]);
}

int main() {

	string str1, str2;
	cin >> str1 >> str2;
	int N;
	scanf("%d\n", &N);
	string match;
	//getline(cin, match);

	char ch[100];

	bool ok;
	for (int i = 0; i < N; i++) {
		ok = true;

		//getline(cin, match);
		fgets(ch, sizeof(ch), stdin);
		
		//stringstream ss(match);

		int set1 = 0, set2 = 0;

		bool isTwoWin = false;

		char *p = ch;
		int score1, score2, ucitano;
		for (int i = 1; sscanf(p, "%d:%d%n", &score1, &score2, &ucitano) == 2; i++) {
			p += ucitano;

			bool isMatchEnd = false;

			if (set1 > 2 || set2 > 2) {
				printf("ne\n");
				ok = false;
				break;
			}

			if (i <= 2) {
				if (score1 == 7 && score2 == 6) {
					set1++;
					isMatchEnd = true;
				}
				if (score2 == 7 && score1 == 6) {
					set2++;
					isMatchEnd = true;
				}		
			}

			if (score1 >= 6 && score1 - score2 >= 2) {
				set1++;
				isMatchEnd = true;
			}
			if (score2 >= 6 && score2 - score1 >= 2) {
				set2++;
				isMatchEnd = true;
			}

			if (max(set1, set2) == 2) isTwoWin = true;
			
			if (isMatchEnd) {
				
			}

			// ���� ������� ������
			if (str1.compare("federer") == 0 && score1<score2) {
				printf("ne\n");
				ok = false;
				break;
			}
			// ���� ������� ������
			if (str2.compare("federer") == 0 && score1>score2) {
				printf("ne\n");
				ok = false;
				break;
			}
		}
		
		if (!ok) continue;

		if (!(set1==2 || set2==2)) {
			printf("ne\n");
			continue;
		}

		printf("da\n");
	}

	return 0;
}