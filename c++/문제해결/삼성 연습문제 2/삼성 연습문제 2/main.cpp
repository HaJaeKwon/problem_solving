#include <cstdio>
#include <iostream>
#include <stdlib.h>
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
	int size,i,j, member_point,count, min_point=0;
	
    int *point = new int[300000];
	
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
        cin>>size;
		count=size;
		
        for(i=0; i<size; i++) {
        	cin>>member_point;
            point[i]=member_point+size;
			min_point = max(min_point,member_point+1);
        }
		sort(point, point+300000);
		for(i=0; i<size; i++) {
			if(point[i] >= min_point) break;
			--count;
		}
        /*
        for(i=0; i<size; i++) {
            for(j=0; j<size; j++) {
            	if(point[j] >= point[300000+i] ) {
					--count;
					break;
				}
            }
        }
		*/

		//	�� �κп��� ������ ����Ͻʽÿ�.  
		cout << "Case #" << test_case << endl;
        cout<<count<<endl;
	}
	free(point);

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}