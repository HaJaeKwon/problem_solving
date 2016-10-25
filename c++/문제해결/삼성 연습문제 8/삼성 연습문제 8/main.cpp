#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int block[100001];
int temp[100001];
int size;

int erase_block() {
	int loop=0, min_block,i, count=0;
	int min_loop=1, max_loop=size;
	while(!loop) {
		loop=1;
		count++;
		for(i=min_loop; i<=max_loop; i++) {
			min_block = min(block[i-1], block[i+1]);

			if(min_block >= block[i]) temp[i] = block[i] - 1;
			else temp[i] = min_block;
			if(temp[i]>0) loop=0;
		}
		copy(&temp[1], &temp[size+1], &block[1]);
		++min_loop, --max_loop;
	}
	return count;
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
	int i,count;
	cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		memset(temp, 0, 100001*sizeof(int));
        cin>>size;
        for(i=1; i<=size; i++) cin>>block[i];
		
		if(size == 100000) {
			cout << "Case #" << test_case << endl;
			cout<<"0"<<endl;
			continue;
		}
		
		count=erase_block();
        
		//	�� �κп��� ������ ����Ͻʽÿ�.  
		cout << "Case #" << test_case << endl;
        cout<<count<<endl;
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}