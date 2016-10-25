#include <stdlib.h>
#include <vector>
#include <algorithm>

// �̰Ŵ� c ��Ÿ���� qsort �� ����� �� ���� compare
int ascending_Compare(const int value1,const int value2) {
	int iNum1, iNum2;

	iNum1 = value1;
	iNum2 = value2;

	return iNum1 - iNum2;
}
// �̰Ŵ� c++ ��Ÿ���� std::sort�� ����� �� ���� compare
bool compare(const int &i,const int &j){
        return i>j;
}

int main() {

	int N,n;
	std::vector<int> list;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &n);
		list.push_back(n);
	}
	//std::sort(list, N, sizeof(int), ascending_Compare);
	std::sort(list.begin(), list.end(), compare);
	for(int i=0; i<list.size(); i++) {
		printf("%d ", list[i]);
	}


	return 0;
}