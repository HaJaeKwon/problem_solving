#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

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
	int N, K,i, result;
	int point[200000];
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
        result=0;
		cin>>N>>K;
		for(i=0; i<N; i++) cin>>point[i];
        sort(point, point+N);
		for(i=0; i<K; i++) {
			result += point[N-i-1];
		}
        
		//	�� �κп��� ������ ����Ͻʽÿ�.  
		cout << "Case #" << test_case << endl;
        cout<<result<<endl;
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}