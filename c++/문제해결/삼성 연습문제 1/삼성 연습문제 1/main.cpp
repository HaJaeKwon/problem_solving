#include <cstdio>
#include <iostream>

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
	
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
        int result=0;
    	int count, input;
        cin >> count;
        for(int i=0; i<count; i++) {
			cin>>input;
        	result ^= input;
        }
        
        
        
		//	�� �κп��� ������ ����Ͻʽÿ�.  
		cout << "Case #" << test_case << endl;
        cout << result <<endl;
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}