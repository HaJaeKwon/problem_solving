#include <stdio.h>


struct Point {
	int x;
	int y;
};
int T,M,N,i;
Point ans[10100];

void solve() {
	int x=1,y=0;
	i=0;
	Point temp;
	if(N%2==1) {
		temp.x=0, temp.y=0;
		ans[i++]=temp;
		temp.x=1, temp.y=0;
		ans[i++]=temp;
		x=1,y=1;
	}
	// �� �κ�
	while(y != N) {
		temp.x=x, temp.y=y;
		ans[i++]=temp;
		temp.x=x-1, temp.y=y;
		ans[i++]=temp;
		temp.x=x-1, temp.y=y+1;
		ans[i++]=temp;
		temp.x=x, temp.y=y+1;
		ans[i++]=temp;
		y+=2;
	}
	x++,y--;
	// �Ϻκ�
	if(N%2==1) {
		// ����Ŭ �ݺ�
		while(!(x==2 && y==0)) {
			// ������ �������� �κ�
			while(x!=N) {
				temp.x=x++, temp.y=y;
				ans[i++]=temp;
			}
			x--,y--;
			// ���� �ö󰡴� �κ�
			while(x!=1) {
				temp.x=x--, temp.y=y;
				ans[i++]=temp;
			}
			x++,y--;
		}
		// ������ �������� �κ�
		while(x!=M) {
			temp.x=x++, temp.y=y;
			ans[i++]=temp;
		}
	} else {
		// ¦��
		// ����Ŭ �ݺ�
		while(!(x==2 && y==-1)) {
			// ������ �������� �κ�
			while(x!=N) {
				temp.x=x++, temp.y=y;
				ans[i++]=temp;
			}
			x--,y--;
			// ���� �ö󰡴� �κ�
			while(x!=1) {
				temp.x=x--, temp.y=y;
				ans[i++]=temp;
			}
			x++,y--;
		}
	}

}

void solve2() {
	Point temp;
	int x=0,y=0,boundY=0;
	i=0;
	if(M%2==1) {
		x=M-1, y=0;
		while(x!=-1) {
			temp.x = x--, temp.y=y;
			ans[i++] = temp;
		}
		x=0,y=1,boundY=1;
	}
	while(i<N*M) {
		while(y!=N) {
			temp.x = x, temp.y=y++;
			ans[i++] = temp;
		}
		x++,y--;
		while(y>=boundY) {
			temp.x = x, temp.y=y--;
			ans[i++] = temp;
		}
		x++,y++;
	}
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &M, &N);

		solve2();

		printf("1\n");
		for(int i=0; i<M*N; i++) {
			printf("(%d,%d)\n", ans[i].x, ans[i].y);
		}
	}

	return 0;
}