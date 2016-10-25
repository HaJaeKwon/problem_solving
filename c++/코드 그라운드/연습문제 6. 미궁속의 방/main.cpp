// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>

//long long int N,K, x,y;
int N,K;
char d;

long long int startRoom(long long int count, int x, int y) {
	if(count < N+1) {
		return (count*(count-1)/2) +1;
	} else {
		count = 2*N-x-y+1;
		return (N*N) - (count*(count-1)/2) - count +1;
	}
}

long long int solve(int x, int y) {
	long long int roomStart, roomCount = x+y-1, step;
	if(roomCount <= N) {
		roomStart = startRoom(roomCount,x,y);
		if(roomCount%2==0) {	// �� ������ ¦���� </ ����
			step = x-1;
		} else {			// �� ������ Ȧ���� /> ����
			step = y-1;
		}
	}else {
		roomStart = startRoom(roomCount,x,y);
		long long int tempX, tempY;
		tempX = N-x+1, tempY = N-y+1;
		roomCount = 2*N-x-y+1;;
		if(roomCount%2==0) {	// �� ������ ¦���� </ ����
			step = tempY-1;
		} else {			// �� ������ Ȧ���� /> ����
			step = tempX-1;
		}
	}
	return roomStart + step;
}

long long int solve2(int x, int y) {
	long long int ret=0;
	if(x+y < N) {
		ret = (x+y+1)*(x+y)/2;
		if( (x+y)%2==0 ) ret += (y+1);
		else ret += (x+1);
		return ret;
	} else {
		 return N*N -solve2(N-x-1, N-y-1) +1;
	}
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
        scanf("%lld %lld", &N, &K);
		int x=1,y=1;
		//int x=0,y=0;
		long long int ans=1;
		while(K>0) {
			scanf("%1s", &d);
			if(d=='U') {
				x--;
			} else if(d=='D') {
				x++;
			} else if(d=='L') {
				y--;
			} else if(d=='R') {
				y++;
			}
			ans += solve(x,y);
			//ans += solve2(x,y);
			K--;
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%lld\n", test_case, ans);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}